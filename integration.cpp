#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include "math.h"
#include "Windows.h"
using namespace std;

int main()
{

	double time = 0;
	double delta = 0.05;
	double theta = 90;

	double xpos = 0, ypos = 0;
	double xvel = 0, yvel = 0;

	double acc = 5;

	while (true) {
		//move forward
		if (GetAsyncKeyState(VK_UP)) {
			acc = 5;
		}
		//move backward
		else if (GetAsyncKeyState(VK_DOWN)) {
			acc = -5;
		}
		else acc = 0;

		//turn left
		if (GetAsyncKeyState(VK_LEFT)) {
			theta += 3;
		}
		//turn right
		else if (GetAsyncKeyState(VK_RIGHT)) {
			theta -= 3;
		}

		//stop moving
		if (GetAsyncKeyState(VK_LSHIFT)) {
			xvel = 0;
			yvel = 0;
		}

		xvel += acc * cos(theta * M_PI / 180.0) * delta;
		yvel += acc * sin(theta * M_PI / 180.0) * delta;

		xpos += xvel;
		ypos += yvel;

		printf("X pos: %f Y pos: %f theta: %f\n", xpos, ypos, theta);

		Sleep(delta * 1000);
		time += delta;
	}
	system("PAUSE");
}