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

int c, d, v, ans;
int ar[110];
bool dp[40];

void solve1()
{
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for (int j = 0; j < d; j++)
	{
		for (int i = v; i >= 0; i--)
		{
			if (dp[i] && i + ar[j] <= v)
			{
				dp[i + ar[j]] = true;
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (!dp[i])
		{
			ans++;
			//printf("%d\n", i);
			for (int j = v; j >= 0; j--)
			{
				if (dp[j] && j + i <= v)
				{
					dp[i + j] = true;
				}
			}
		}
	}
}

void solve2()
{
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d%d%d", &c, &d, &v);
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &ar[i]);
		}
		sort(ar, ar + d);
		ans = 0;
		if (c == 1)
		{
			solve1();
		}
		else
		{
			solve2();
		}
		printf("Case #%d: %d\n", q + 1, ans);
	}
	return 0;
}