// CodeJam 2013
// Autor: Benjamín de la Fuente Ranea

#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

#include "BigIntegerLibrary.hh"

#define FILE_INPUT	"B-small-attempt0"

void moveX(int _moveNdx, int& _x, string& _str)
{
	if (_x > 0)
	{
		_str += "E";
		_x -= _moveNdx;
	}
	else
	{
		_str += "W";
		_x += _moveNdx;
	}
}

void moveY(int _moveNdx, int& _y, string& _str)
{
	if (_y > 0)
	{
		_str += "N";
		_y -= _moveNdx;
	}
	else
	{
		_str += "S";
		_y += _moveNdx;
	}
}

void move(int _x, int _y, string& _str)
{
	while (_x != 0 || _y != 0)
	{
		const int moveNdx = _str.length() + 1;
		const int absX = abs(_x);
		const int absY = abs(_y);
		if (absX == moveNdx)
			moveX(moveNdx, _x, _str);
		else if (absY == moveNdx)
			moveY(moveNdx, _y, _str);
		else if (moveNdx < absX)
			moveX(moveNdx, _x, _str);
		else if (moveNdx < absY)
			moveY(moveNdx, _y, _str);
		else if (_x != 0)
		{
			if (_x > 0)
			{
				_str += "W";
				_x += moveNdx;
			}
			else
			{
				_str += "E";
				_x -= moveNdx;
			}
		}
		else if (_y != 0)
		{
			if (_y > 0)
			{
				_str += "S";
				_y += moveNdx;
			}
			else
			{
				_str += "N";
				_y -= moveNdx;
			}
		}
	}
}

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	int numCases;
	scanf("%d\n", &numCases);
	for (int i = 1; i <= numCases; ++i)
	{
		int X, Y;
		scanf("%d %d\n", &X, &Y);

		string str;
		move(X, Y, str);

		printf("Case #%d: %s\n", i, str.c_str());
	}
}
