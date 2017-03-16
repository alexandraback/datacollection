/*
	Author: elfness@UESTC
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;
const int V = 120;
char s[V], t[V], q[V];
int _, n, m, S;
int nxt[V][V], vis[V], mx[V][V];
double dp[V][V][V];
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d", &_);
	for(int ca = 1; ca <= _; ++ca)
	{
		scanf("%d%d%d", &n, &m, &S);
		scanf("%s%s", s, t);
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; ++i)
		++vis[s[i] - 'A'];
		bool can = true;
		for(int i = 0; i < m; ++i)
		if(vis[t[i] - 'A'] == 0) can = false;
		if(!can)
		{
			printf("Case #%d: 0.0\n", ca);
			continue;
		}
		for(int i = 0; i <= m; ++i)
		for(int j = 0; j < 26; ++j)
		{
			nxt[i][j] = 0;
			for(int k = 0; k < i; ++k) q[k] = t[k];
			q[i] = j + 'A';
			for(int k = 1; k <= min(i + 1, m); ++k)
			{
				bool match = true;
				for(int l = 0; l < k && match; ++l)
				{
					if(t[l] != q[l + i + 1 - k])
					match = false;
				}
				if(match) nxt[i][j] = k;
			}
		}
		for(int i = 0; i <= S; ++i)
		for(int j = 0; j <= m; ++j)
		mx[i][j] = -1000000000;
		mx[0][0] = 0;
		for(int i = 0; i < S; ++i)
		for(int j = 0; j <= m; ++j)
		for(int k = 0; k <= 26; ++k)
		if(vis[k] != 0)
		{
			int cnt = 0;
			if(nxt[j][k] == m) cnt = 1;
			mx[i + 1][nxt[j][k]] = max(mx[i + 1][nxt[j][k]], mx[i][j] + cnt);
		}
		int ret = 0;
		for(int j = 0; j <= m; ++j)
		ret = max(ret, mx[S][j]);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1.0;
		for(int i = 0; i < S; ++i)
		for(int j = 0; j <= m; ++j)
		for(int k = 0; k <= ret; ++k)
		for(int l = 0; l < 26; ++l)
		if(vis[l] != 0)
		{
			double p = 1.0 * vis[l] / n;
			int cnt = 0;
			if(nxt[j][l] == m) cnt = 1;
			dp[i + 1][nxt[j][l]][k + cnt] += dp[i][j][k] * p;
		}
		double pret = 0.0;
		for(int j = 0; j <= m; ++j)
		for(int k = 0; k <= ret; ++k)
		pret += dp[S][j][k] * k;
		printf("Case #%d: %.8f\n", ca, ret - pret);
	}
	return 0;
}
