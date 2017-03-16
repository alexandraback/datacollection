
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <iomanip>
#define UINT64 unsigned __int64
using namespace std;
ifstream  fin("b.txt");
ofstream  fout("c.txt");

char boardArr[50][50];


void solve1(unsigned int r, unsigned int c, unsigned int noMine)
{
	unsigned int i;

	boardArr[0][0] = 'c';
	noMine--;

	if (1 == r)
	{
		for (i = 1; i < c; i++)
		{
			if (noMine)
			{
				boardArr[0][i] = '.';
				noMine--;
			}
			else
			{
			}
		}
	}
	else
	{
		for (i = 1; i < r; i++)
		{
			if (noMine)
			{
				boardArr[i][0] = '.';
				noMine--;
			}
			else
			{
			}
		}
	}
}

void solve2(unsigned int r, unsigned int c, unsigned int noMine)
{
	unsigned int i;

	boardArr[0][1] = '.';
	boardArr[1][1] = '.';
	boardArr[1][0] = '.';

	noMine -= 4;

	if (2 == r)
	{
		for (i = 2; i < c; i++)
		{
			if (noMine)
			{
				boardArr[0][i] = '.';
				boardArr[1][i] = '.';

				noMine-=2;
			}
			else
			{
	
			}
		}
	}
	else
	{
		for (i = 2; i < r; i++)
		{
			if (noMine)
			{
				boardArr[i][0] = '.';
				boardArr[i][1] = '.';

				noMine -= 2;
			}
			else
			{
				
			}
		}
	}
}

void solveRegular(unsigned int r, unsigned int c, unsigned int maxRow, unsigned int maxCol, unsigned int noMineReminder)
{
	unsigned int i;
	unsigned int j;

	for (i = 0; i < maxRow; i++)
	{
		for (j = 0; j < maxCol; j++)
		{
			boardArr[i][j] = '.';
		}
	}

	if (1 == noMineReminder)
	{
		boardArr[maxRow-1][maxCol-1] = '*';

		if (r>c)
		{
			boardArr[maxRow][0] = '.';
			boardArr[maxRow][1] = '.';
		}
		else
		{
			boardArr[0][maxCol] = '.';
			boardArr[1][maxCol] = '.';
		}


	}
	else
	{
		if (r >c)
		{
			for (j = 0; j < noMineReminder; j++)
			{
				boardArr[maxRow][j] = '.';
			}
		}
		else
		{
			for (j = 0; j < noMineReminder; j++)
			{
				boardArr[j][maxCol] = '.';
			}
		}
	
	}

	boardArr[0][0] = 'c';
}


void solveSqrt(unsigned int r, unsigned int c, unsigned int maxRow, unsigned int maxCol, unsigned int noMineReminder)
{
	unsigned int i;
	unsigned int j;

	for (i = 0; i < maxRow; i++)
	{
		for (j = 0; j < maxCol; j++)
		{
			boardArr[i][j] = '.';
		}
	}

	if (1 == noMineReminder)
	{
		boardArr[maxRow - 1][maxCol - 1] = '*';

		if (r>c)
		{
			boardArr[maxRow][0] = '.';
			boardArr[maxRow][1] = '.';
		}
		else
		{
			boardArr[0][maxCol] = '.';
			boardArr[1][maxCol] = '.';
		}
	}
	else
	{
		if (r >c)
		{
			for (j = 0; j < noMineReminder; j++)
			{
				boardArr[maxRow][j] = '.';
			}
		}
		else
		{
			for (j = 0; j < noMineReminder; j++)
			{
				boardArr[j][maxCol] = '.';
			}
		}

	}

	boardArr[0][0] = 'c';
}


void solve(unsigned int r, unsigned int c, unsigned int m)
{
	unsigned int i;
	unsigned int j;
	unsigned int noMine = r*c - m;
	unsigned int minColOrRow = min(r, c);
	unsigned int noMineSqrt = (unsigned int)sqrt(noMine);
	unsigned int noMineReminder;
	bool bIsSolve = true;

	memset(boardArr, '*', sizeof(boardArr));
	boardArr[0][0] = 'c';

	if (noMine == 1)
	{
		//do nothing
	}
	else if (1 == minColOrRow)
	{
		solve1(r, c, noMine);
	}
	else if ((2 == noMine) || (3 == noMine) || (5 == noMine) || (7 == noMine))
	{
		bIsSolve = false;
	}
	else if (2 == minColOrRow)
	{
		if (noMine&1)
		{
			bIsSolve = false;
		}
		else
		{
			solve2(r, c, noMine);
		}
	}
	else 
	{
		unsigned int maxRow;
		unsigned int maxCol;

		if (noMineSqrt<minColOrRow)
		{
			noMineReminder = noMine - (noMineSqrt*noMineSqrt);
			if (noMineSqrt<noMineReminder)
			{
				noMineReminder = noMine - ((noMineSqrt+1)*noMineSqrt);
				solveSqrt(r, c, noMineSqrt+1, noMineSqrt, noMineReminder);
			}
			else
			{
				noMineReminder = noMine - (noMineSqrt*noMineSqrt);
				solveSqrt(r, c, noMineSqrt, noMineSqrt, noMineReminder);
			}
			
		}
		else if (noMineSqrt >= c)
		{
			maxRow = noMine/ c;

			noMineReminder = noMine - (maxRow*c);
			solveRegular(r, c,maxRow, c, noMineReminder);
		}
		else
		{
			maxCol = noMine / r;

			noMineReminder = noMine - (maxCol*r);
			solveRegular(r, c, r, maxCol, noMineReminder);
		}
	}


	if (bIsSolve)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				fout << boardArr[i][j];
			}
			fout << endl;
		}
	}
	else
	{
		fout << "Impossible" << endl;
	}

}

int main(void)
{
	unsigned int numOfTests;
	unsigned int r;
	unsigned int c;
	unsigned int m;
	unsigned int i;
	char b;
	fin >> b;
	fin >> b;
	fin >> b;
	fin >> numOfTests;
	

	for (i = 0; i<numOfTests; i++)
	{
		fin >> r>>c>>m;
	
		fout << "Case #"<<i+1<<":"<<endl;
		solve(r,c,m);
		
	}
}
