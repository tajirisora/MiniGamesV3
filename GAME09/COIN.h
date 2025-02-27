#pragma once
#include "GAME_OBJECT.h"
#include "LINE.h"
#include "HOLE.h"
#include "../../libOne/inc/VECTOR2.h"
#include <vector>

namespace GAME09
{
    class COIN :
        public GAME_OBJECT
    {
	public:
		struct DATA {
			int img;
			float imgSize;
			VECTOR2 startPos;
			VECTOR2 startV; //初速
			float radius;
			float friction; //摩擦係数
			float limmitV;  //速度の衝突方向成分の上限値

			float sw;       //線の太さ
		};
	private:
		DATA Coin;
		VECTOR2 Pos;    //重心位置
		VECTOR2 V;      //速度
		float Theta;    //回転角度
		float Omega;    //角速度
		float M;        //質量
		float I;        //慣性モーメント
		float R;        //半径

		bool Active;

		//符号を返す(正なら1、0なら0、負なら-1)
		int Sign(float A) {
			return (A > 0) - (A < 0);
		}

		//小さいほうの値を返す
		float Min(float a, float b) {
			return a < b ? a : b;
		}
	public:
		COIN(class GAME* game);
        ~COIN();
        void create();
        void init();
		void update();
		void draw();
		void addImpulseLocal(const VECTOR2& impulse, const VECTOR2& addLocalPos);
		void addImpulse(const VECTOR2& impulse, const VECTOR2& addPos);
		void applyForce(const VECTOR2& force);
		void collisionWalls(std::vector<LINE>& walls);
		int collisionHoles(std::vector<HOLE>& holes, HOLE* winHole);
		
		void setActive(bool active) { Active = active; }
		bool active() { return Active; }
		VECTOR2 getPos() { return Pos; }
    };
}