/* by Ashar Fuadi (fushar) */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i = 0, _n = (int)n; i < _n; i++)
#define FOR(i,a,b) for (int i = (int)a, _b = (int)b; i <= _b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

#define pb push_back
#define mp make_pair

int T;
int R, C, M;

int dp[55][55][2505];
char grid[55][55];

int DP(int i, int j, int m)
{
	if (j > C)
		return 0;
	if (i == R)
		return m ? 0 : 1;
	
	if (dp[i][j][m]== -1)
	{
		dp[i][j][m] = 0;
		if (j < C)
			dp[i][j][m] |= DP(i, j+1, m);
		if (m >= j && j != C-1)
			dp[i][j][m] |= DP(i+1, j, m-j);
	}
	return dp[i][j][m];
}

void trace(int i, int j, int m)
{
	if (i == R)
		return;
	
	if (j < C && DP(i, j+1, m))
		trace(i, j+1, m);
	else
	{
		REP(k, j)
			grid[i][k] = '*';
		trace(i+1, j, m-j);
	}
}

int solve()
{
	RESET(dp, -1);
	REP(i, C-1)
		if (i*2 <= M && DP(2, i, M-i*2))
			return i;
	return -1;
}

int main()
{
	scanf("%d", &T);
	REP(tc, T)
	{
		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", tc+1);
		
		if (R == 1)
		{
			printf("c");
			REP(j, C-M-1)
				printf(".");
			REP(j, M)
				printf("*");
			printf("\n");
			continue;
		}
		
		if (C == 1)
		{
			printf("c\n");
			REP(j, R-M-1)
				printf(".\n");
			REP(j, M)
				printf("*\n");
			continue;
		}
		
		if (M == R*C-1)
		{
			REP(i, R)
			{
				REP(j, C)
				{
					if (i == 0 && j == C-1)
						printf("c");
					else
						printf("*");
				}
				printf("\n");
			}
			continue;
		}
		
		int first;
		
		if ((first = solve()) != -1)
		{
			REP(i, R)
			{
				REP(j, C)
					grid[i][j] = '.';
			}
			trace(2, first, M-first*2);
			REP(j, first)
				grid[0][j] = grid[1][j] = '*';
			grid[0][C-1] = 'c';
			REP(i, R)
			{
				REP(j, C)
					printf("%c", grid[i][j]);
				printf("\n");
			}
		}
		else
		{
			swap(R, C);
			if ((first = solve()) != -1)
			{
				REP(i, R)
				{
					REP(j, C)
						grid[i][j] = '.';
				}
				trace(2, first, M-first*2);
				REP(j, first)
					grid[0][j] = grid[1][j] = '*';
				grid[0][C-1] = 'c';
				REP(j, C)
				{
					REP(i, R)
						printf("%c", grid[i][j]);
					printf("\n");
				}
			}
			else
				printf("Impossible\n");
		}
		
		fflush(stdout);
	}
}
