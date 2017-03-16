#pragma comment(linker, "/STACK:33554432")

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <memory.h>
#include <iostream>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>

using namespace std;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef long long LL;

int t, k, n;

int cnt[1 << 8];
int dp[1 << 20];
int path[1 << 20];
vint keys[1 << 8];
int need[1 << 8];

int go(int mask)
{
	if (mask == (1 << n) - 1)
		return 1;
	int & res = dp[mask];
	if (res != -1)
		return res;
	res = 0;
	for(int i = 0; i < n; ++i)
	{
		if (!(mask & (1 << i)))
		{
			if (!cnt[need[i]])
				continue;
			cnt[need[i]]--;
			for(int j = 0; j < keys[i].size(); ++j)
				cnt[keys[i][j]]++;
			if (go(mask | (1 << i)))
			{
				path[mask] = i;
				return res = 1;
			}
			for(int j = 0; j < keys[i].size(); ++j)
				cnt[keys[i][j]]--;
			cnt[need[i]]++;
		}
	}
	return res;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &k, &n);
		for(int j = 0; j < k; ++j)
		{
			int key;
			scanf("%d", &key);
			cnt[key]++;
		}
		for(int j = 0; j < n; ++j)
		{
			scanf("%d", &need[j]);
			int m;
			scanf("%d", &m);
			keys[j].clear();
			keys[j].resize(m);
			for(int k = 0; k < m; ++k)
				scanf("%d", &keys[j][k]);
		}
		printf("Case #%d: ", i + 1);
		memset(dp, -1, sizeof(dp));
		if (!go(0))
			printf("IMPOSSIBLE\n");
		else
		{
			int mask = 0;
			for(int i = 0; i < n; ++i)
			{
				printf("%d ", path[mask] + 1);
				mask |= 1 << path[mask];
			}
			printf("\n");
		}
	}
	return 0;
}