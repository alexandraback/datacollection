#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int maxN = 1000100;

int dp[maxN];

int rev(int v)
{
	int res = 0;
	while (v > 0)
	{
		res = res * 10 + v % 10;
		v /= 10;
	}
	return res;
}

void init()
{
	dp[1] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		if (dp[i] == 0)
		{
			dp[i] = dp[i - 1] + 1;
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
		int ri = rev(i);
		if (ri > i && ri < maxN)
		{
			dp[ri] = dp[i] + 1;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", q + 1, dp[n]);
	}
	return 0;
}