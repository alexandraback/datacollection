// Diamonds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cassert>
#include <cstring>

int debug = 0;

typedef struct
{
	static const int xOffset = 10;
	int cell[20][20];

	int get(int x, int y)
	{
		return cell[x+xOffset][y];
	}

	void set(int x, int y)
	{
		cell[x+xOffset][y] = 1;
        if (debug) printf("Set %d, %d\n", x, y);
	}

	int clear(int x, int y)
	{
		cell[x+xOffset][y] = 0;
	}
} Grid;

#define OFFSET 10

int X, Y;

double sum;
int START_Y = 10;

void Drop(int x, int y, Grid g, int n, double p);

int _tmain(int argc, _TCHAR* argv[])
{
	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int N;
		Grid g;
		
		memset(&g, 0, sizeof(g));

		assert(scanf("%d %d %d", &N, &X, &Y) == 3);

		sum = 0.0;

		Drop(0, START_Y, g, N, 1.0);
		
		printf("Case #%d: %f\n", t, sum);
	}
}

void Drop(int x, int y, Grid g, int n, double p)
{
	assert(x > -10);
	assert(x < 10);
	assert(y >= 0);
	assert(y < 11);

	if (n == 0)
	{
      if ((X > -10) && (X < 10) && (Y > -10) && (Y < 10))
	  {
      if (g.get(X, Y))
		  sum += p;
	  }
	  return;
	}

	while (1)
	{
		if (debug)
	     printf("n %d x %d y %d\n", n, x, y);


	    if (y == 0)
		{
			g.set(x, y);
			Drop(0, START_Y, g, n-1, p);
			break;
		}
		else if ((g.get(x-1, y-1) == 1) && (g.get(x+1, y - 1) == 1))
		{
			g.set(x, y);
			Drop(0, START_Y, g, n-1, p);
			break;
		}
		else if ((y >= 2) && (g.get(x, y - 2) == 0))
		{
			y -= 2;
		}
		else if ((g.get(x-1, y-1) == 0) && (g.get(x+1, y - 1) == 1))
		{
			Drop(x-1, y-1, g, n, p);
			break;
		}
		else if ((g.get(x-1, y-1) == 1) && (g.get(x+1, y - 1) == 0))
		{
			Drop(x+1, y-1, g, n, p);
			break;
		}
		else
		{
			Drop(x-1, y-1, g, n, p*0.5);
			Drop(x+1, y-1, g, n, p*0.5);
			break;
   		}
	}
}
