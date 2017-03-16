// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
using namespace std;
ifstream in("A-small-attempt0.in");
ofstream out("out.txt");

bool Is(char g, char c)
{
	return g == 'T' || g == c;
}

char game[4][4];

bool Check(char c)
{
	for(int x = 0;x < 4;++x)
	{
		if(Is(game[x][0],c) && Is(game[x][1],c) && Is(game[x][2],c) && Is(game[x][3],c))
			return true;
	}
	for(int x = 0;x < 4;++x)
	{
		if(Is(game[0][x],c) && Is(game[1][x],c) && Is(game[2][x],c) && Is(game[3][x],c))
			return true;
	}
	if(Is(game[0][0],c) && Is(game[1][1],c) && Is(game[2][2],c) && Is(game[3][3],c))
		return true;
	if(Is(game[0][3],c) && Is(game[1][2],c) && Is(game[2][1],c) && Is(game[3][0],c))
		return true;
	return false;
}
bool bFoundPoint;
void  Solve()
{
	if(Check('X'))
		out << "X won";
	else if(Check('O'))
		out << "O won";
	else if(bFoundPoint)
		out << "Game has not completed";
	else
		out << "Draw";

}
int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	in >> T;
	for(int i = 0;i<T;++i)
	{
		bFoundPoint = false;
		for(int y = 0;y<4;++y)
		{
			for(int x = 0;x<4;++x)
			{
				in >> game[x][y];
				if(game[x][y] == '.')
					bFoundPoint = true;
			}
		}
		out << "Case #" << (i+1) << ": ";
		Solve();
		out << endl;
	}
	return 0;
}

