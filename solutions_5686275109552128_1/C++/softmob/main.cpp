#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

bool used[1001][1001];
map<int, map<int, int> > dp;

int dfs(int mx, int x, int h = 0)
{
	int ans = mx;
	if (mx <= x)
		return 0;
	if (used[mx][x])
		return dp[mx][x];

	for (int val = 1; val <= mx - val; ++val)
	{
		int a = val;
		int b = mx - val;
		int cur = dfs(a, x, h + 1) + dfs(b, x, h + 1) + 1;
		ans = min(ans, cur);
	}
	return ans + h;
}

void solve(int test)
{
	int d;
	cin >> d;
	vector<int> v(d);
	for (int i = 0; i < d; ++i)
	{
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < d; ++i)
	{
		ans = max(ans, v[i]);
	}
	for (int x = 1000; x >= 1; --x)
	{
		int cur = 0;
		for (int i = 0; i < d; ++i)
		{
			int tmp = dfs(v[i], x);
			cur += tmp;	
		}
		ans = min(ans, x + cur);
	}
	cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int x = 1; x <= 1000; ++x)
	{
		for (int j = 1; j <= 1000; ++j)
		{
			dp[j][x] = dfs(j, x);
			used[j][x] = true;
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i + 1);
	}
	return 0;
}