#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;

#pragma comment(linker,"/STACK:100000000")

double dp[2050][2050];

void solve(int T)
{
	int n, x, y;
	int i, j;
	scanf("%d%d%d", &n, &x, &y);
	x = abs(x);
	int lvl = 0;
	while ((lvl + 1)*(2*lvl + 1) <= n) lvl++;
	if (y <= -x + 2*(lvl - 1))
	{
		printf("Case #%d: %.12lf\n", T, 1.);
		return;
	}
	if (y > -x + 2*lvl)
	{
		printf("Case #%d: %.12lf\n", T, 0.);
		return;
	}
	for (i = 0; i <= 2*lvl; ++i)
		for (j = 0; j <= 2*lvl; ++j)
		{
			if (i == 0 && j == 0)
			{
				dp[0][0] = 1;
				continue;
			}
			dp[i][j] = 0;
			if (i > 0)
			{
				if (j < 2*lvl)
					dp[i][j] += dp[i - 1][j]*0.5;
				else
					dp[i][j] += dp[i - 1][j];
			}
			if (j > 0)
			{
				if (i < 2*lvl)
					dp[i][j] += dp[i][j - 1]*0.5;
				else
					dp[i][j] += dp[i][j - 1];
			}
//			printf("%d %d %.5lf\n", i, j, dp[i][j]);
		}
	int m = n - lvl*(2*lvl - 1);
	double ans = 0;
	for (i = 0; i <= min(m, 2*lvl); ++i)
	{
//		printf("%d %d %.5lf\n", i, m - i, dp[i][m - i]);
		if (y < i && m - i <= 2*lvl)
			ans += dp[i][m - i];
	}
	printf("Case #%d: %.12lf\n", T, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, T;
	scanf("%d", &T);
	for (i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}