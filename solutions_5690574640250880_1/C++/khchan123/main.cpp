#include "stdio.h"
#include "string.h"
#include "math.h"
#include "set"
#include "algorithm"
#include <gmpxx.h>

using namespace std;

/**************** debug ***************/
//#define DBG 1
#ifdef DBG
#define chkpoint(...) { fprintf(stderr, "[%s:%d]", __func__, __LINE__);fprintf(stderr, __VA_ARGS__); };
#define debug(...) { fprintf(stderr, __VA_ARGS__); };
#else
#define chkpoint(...) 
#define debug(...) 
#endif
/**************** debug ***************/

/**************** Useful macro ***************/
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define PLACE_MIN(a, b) a = MIN(a, b)
#define PLACE_MAX(a, b) a = MAX(a, b)
#define MPZ2STR(x) (x.get_str(10).c_str())
/**************** Useful macro ***************/
char grid[64][64];

#define PLACE(x,y) place(x,y,R,C)
bool place(int x, int y, int R, int C)
{
	if (x < 0 || y < 0) return false;
	if (x >= R || y >= C) return false;
	if (grid[x][y] == '.')
	{
		grid[x][y] = '*';
		debug("Placed at [%d][%d]\n", x, y);
		return true;
	}
	return false;
}

#define CAL(x,y) cal(x,y,R,C)
int cal(int x, int y, int R, int C)
{
	if (x < 0 || y < 0) return 0;
	if (x >= R || y >= C) return 0;
	return grid[x][y] == '*' ? 1 : 0;
}

#define VERIFY(x,y) verify(x,y,R,C)
bool verify(int x, int y, int R, int C)
{
	if (x < 0 || y < 0) return false;
	if (x >= R || y >= C) return false;
	if (grid[x][y] == 0)
	{
		debug("Verified at [%d][%d]\n", x, y);
		return true;
	}
	return false;
}

void solve(int R, int C, int M)
{
	int i, j;
	bool valid = true;

	debug("R=%d, C=%d, M=%d\n", R, C, M);
	for (i = 0; i < R; ++i)
	{
		for (j = 0; j < C; ++j)
		{
			grid[i][j] = '.';
		}
	}
	grid[R-1][C-1] = 'c';

	// fill
	int r = 0, c = 0;
	while (M>0)
	{
		if (R-r < C-c)
		{
			for (i = 0; i < R; ++i)
			{
				if (M == 1 && i == R-2 && c < C-1)
					break;
				if (M > 0 && PLACE(i, c))
					M--;
			}
			c++;
		}
		else
		{
			for (j = 0; j < C; ++j)
			{
				if (M == 1 && j == C-2 && r < R-1)
					break;
				if (M > 0 && PLACE(r, j))
					M--;
			}
			r++;
		}
	}

	if (M > 0)
		printf("ERROR!!!!!!!!!!!!!!! Fill mines wronly\n");
	
	// calculate
	for (i = 0; i < R; ++i)
	{
		for (j = 0; j < C; ++j)
		{
			if (grid[i][j] == '.' || grid[i][j] == 'c')
			{
				grid[i][j] = 
					CAL(i-1, j-1) +
					CAL(i-1, j) +
					CAL(i-1, j+1) +
					CAL(i,   j-1) +
					CAL(i,   j+1) +
					CAL(i+1, j-1) +
					CAL(i+1, j) +
					CAL(i+1, j+1);
			}
		}
	}

	// verify
	for (i = 0; valid && (i < R); ++i)
	{
		for (j = 0; valid && (j < C); ++j)
		{
			if (grid[i][j] < 10 && grid[i][j] >= 0 
					&& !(i == R-1 && j == C-1))
			{
				if (VERIFY(i-1, j-1) ||
						VERIFY(i-1, j) ||
						VERIFY(i-1, j+1) ||
						VERIFY(i,   j-1) ||
						VERIFY(i,   j+1) ||
						VERIFY(i+1, j-1) ||
						VERIFY(i+1, j) ||
						VERIFY(i+1, j+1))
				{
					// ok
				}
				else
				{
					valid = false;
					break;
				}
			}
		}
	}
	grid[R-1][C-1] = 'c';
	
	if (!valid)
	{
		printf("Impossible\n");
#ifndef DBG
		return;
#endif
	}
	for (i = 0; i < R; ++i)
	{
		for (j = 0; j < C; ++j)
		{
			if (grid[i][j] < 10)
#ifdef DBG
				grid[i][j] += '0';
#else
				grid[i][j] = '.';
#endif
			printf ("%c", grid[i][j]);
		}
		printf("\n");
	}

	return;
}

int main()
{
	int tt, T;
	int R, C, M;

	scanf("%d\n", &T);
	
	for (tt = 1; tt <= T; ++tt)
	{
		scanf("%d %d %d\n", &R, &C, &M);
		printf("Case #%d:\n", tt);
		solve(R, C, M);
	}
	return 0;
}
