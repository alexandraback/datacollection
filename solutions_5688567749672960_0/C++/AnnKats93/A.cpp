#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;

int dp[1000005];

int rev(int x)
{
	int ans = 0;
	while (x > 0)
		ans *= 10, ans += x % 10, x /= 10;
	return ans;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		int re = rev(i);
		if (re < i && (i % 10 != 0))
			dp[i] = min(dp[i - 1], dp[re]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}

	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", tt + 1, dp[n]);
	}


	return 0;
}
