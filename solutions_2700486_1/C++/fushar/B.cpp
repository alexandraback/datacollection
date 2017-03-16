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

int T, N, X, Y;
double dp[3000][3000];

double solve()
{
	ll S = X + Y + 1;
	ll need = S * (S + 1) / 2;
	if (X == 0)
		return N >= need;
	if (N >= need)
		return 1;
	need = (S - 2) * (S - 1) / 2;
	if (N < need)
		return 0;

	double rem = N - need;

	RESET(dp, 0);
	for (int i = rem; i >= 0; i--)
		for (int j = rem; j >= 0; j--)
		{

			if (i + j > rem)
				continue;
			if (i + j == rem)
				dp[i][j] = j >= (Y + 1);
			else
			{
				if (i == S-1)
					dp[i][j] = dp[i][j+1];
				else if (j == S-1)
					dp[i][j] = dp[i+1][j];
				else
					dp[i][j] = (dp[i][j+1] + dp[i+1][j]) / 2;
			}
		}
	return dp[0][0];
}

int main()
{
	scanf("%d", &T);
	REP(tc, T)
	{
		scanf("%d%d%d", &N, &X, &Y);
		X = std::abs(X);
		printf("Case #%d: %.10lf\n", tc+1, solve());
	}
}