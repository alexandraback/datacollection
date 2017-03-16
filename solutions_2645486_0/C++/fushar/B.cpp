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

const int MAX = 16;

int T, E, R, N, V[MAX];
int dp[MAX][MAX];

int DP(int i, int e)
{
	if (i == N)
		return 0;

	if (dp[i][e] == -1)
	{
		dp[i][e] = 0;
		REP(f, e+1)
			dp[i][e] = max(dp[i][e], V[i] * f + DP(i+1, min(E, e - f + R)));
	}
	return dp[i][e];
}

int main()
{
	scanf("%d", &T);
	REP(tc, T)
	{
		scanf("%d%d%d", &E, &R, &N);
		REP(i, N)
			scanf("%d", &V[i]);

		RESET(dp, -1);
		printf("Case #%d: %d\n", tc+1, DP(0, E));
	}
}