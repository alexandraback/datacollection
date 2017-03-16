
#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility>
#include <functional>
#include <popcntintrin.h>
#include <x86intrin.h>

using namespace std;

#define forl(i,a,b) for(int i = a; i < b; ++i)

int popcnt64(uint64_t val)
{
	return _mm_popcnt_u64(val);
}

bool board[1001][1001];
int width, height;

void resetBoard(int w, int h) 
{
	width = w;
	height =h;
	forl(x,0,w)
		forl(y,0,h)
			board[x][y] = false;
}

void setBoardBasic(int64_t scarynumber)
{
	forl(x,0,width)
	{
		forl(y,0,height)
		{
			int index = y*width+x;
			int64_t bit = 1 << index;
			if (scarynumber & bit) board[x][y] = true;
		}
	}
}

void debugOut()
{
	forl(y,0,height)
	{
		forl(x,0,width)
		{
			if (board[x][y]) cerr << "X";
			else cerr << ".";
		}
		cerr << endl;
	}
}

bool scanPos(int x, int y)
{
	if (board[x][y]) return true;
	forl(_x,0,x+1)
	{
		if (_x == x) return false;
		if (board[_x][y]) break;
	}
	forl(_x,x,width+1)
	{
		if (_x == width) return false;
		if (board[_x][y]) break;
	}
	forl(_y,0,y+1)
	{
		if (_y == y) return false;
		if (board[x][_y]) break;
	}
	forl(_y,y,height+1)
	{
		if (_y == height) return false;
		if (board[x][_y]) break;
	}
	return true;
}

int scanEnclosed()
{
	int count = 0;
	forl(x,0,width)
	{
		forl(y, 0, height)
		{
			if (scanPos(x,y))
				count++;
		}
	}
	return count;
}

int main()
{
	int numCases;
	scanf("%d", &numCases);
	forl(i,1,numCases+1)
	{
		int w, h, numThings;
		scanf("%d %d %d", &w, &h, &numThings);
		int size = w*h;
		int top = 1 << size;
		int best = 999999999;
		forl(ct, 0, top)
		{
			int mines = popcnt64(ct);
			if (mines >= best || mines > numThings)
			{
				continue;
			}
			resetBoard(w,h);
			setBoardBasic(ct);
			int tmp = scanEnclosed();
			if (tmp == numThings)
			{
				//cerr << "ct " << ct <<" mines " << mines << " best " << best << " enclosed " << tmp << endl;
				//debugOut();
				if (mines < best) best = mines;
			}
		}

		cout << "Case #" << i << ": ";
		cout << best;
		cout << endl;
	}
}
