/*
 * D.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

int keys[201];
int gates[201][401];
int open[201];
int numOfKeys[201];
int tc, k, n;

/*int ans[201];
 int sz;
 map<int, int> m;
 bool vis[201];
 bool BT()
 {
 bool f = 1;
 for (int i = 0; i < n; ++i)
 {
 if (vis[i])
 continue;
 f = 0;
 if (!m[open[i]])
 continue;
 --m[open[i]];
 vis[i] = 1;
 ans[sz++] = i + 1;
 for (int j = 0; j < numOfKeys[i]; ++j)
 ++m[gates[i][j]];
 if (BT())
 return 1;
 for (int j = 0; j < numOfKeys[i]; ++j)
 --m[gates[i][j]];
 ++m[open[i]];
 vis[i] = 0;
 --sz;
 }
 return f;
 }*/

int dp[1 << 21];

int DP(int mask)
{
	if (__builtin_popcount(mask) == n)
		return 1;
	int &res = dp[mask];
	if (res != -1)
		return res;
	map<int, int> m;
	for (int i = 0; i < k; ++i)
		++m[keys[i]];
	for (int i = 0; i < n; ++i)
	{
		if ((mask >> i) & 1)
		{
			--m[open[i]];
			for (int j = 0; j < numOfKeys[i]; ++j)
				++m[gates[i][j]];
		}
	}
	res = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((mask >> i) & 1)
			continue;
		if (!m[open[i]])
			continue;
		if (DP(mask | (1 << i)))
			return res = 1;
	}
	return res;
}

void build(int mask)
{
	if (__builtin_popcount(mask) == n)
	{
		printf("\n");
		return;
	}
	map<int, int> m;
	for (int i = 0; i < k; ++i)
		++m[keys[i]];
	for (int i = 0; i < n; ++i)
	{
		if ((mask >> i) & 1)
		{
			--m[open[i]];
			for (int j = 0; j < numOfKeys[i]; ++j)
				++m[gates[i][j]];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if ((mask >> i) & 1)
			continue;
		if (!m[open[i]])
			continue;
		if (DP(mask | (1 << i)))
		{
			printf(" %d", i + 1);
			build(mask | (1 << i));
			return;
		}
	}
}

int main()
{
	//	cout << (idx[0] = idx.size() - 1) << endl;
	//	return 0;
	//	freopen("d.in", "rt", stdin);
	freopen("D-small-attempt1.in", "rt", stdin);
	freopen("d.out1", "wt", stdout);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		cerr << T << endl;
		//sz = 0;
		//m.clear();
		//memset(vis, 0, sizeof vis);
		scanf("%d%d", &k, &n);
		for (int i = 0; i < k; ++i)
			scanf("%d", keys + i);//, ++m[keys[i]];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", open + i, numOfKeys + i);
			for (int j = 0; j < numOfKeys[i]; ++j)
				scanf("%d", gates[i] + j);
		}

		printf("Case #%d:", T);
		memset(dp, -1, sizeof dp);
		if (!DP(0))
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		//		for (int i = 0; i < n; ++i)
		//			printf(" %d", ans[i]);
		build(0);
	}
	return 0;
}
