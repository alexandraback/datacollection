/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: c.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-05-11
*   last modified: 2014-05-11 18:51:19
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define foreach(it, s) for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++)

const int maxn = 20;
bool block[maxn][maxn];
bool vis[maxn][maxn];
int n, m, K;
const int d[4][2] = {1,0, -1,0, 0,1, 0,-1};
#define isValid(x,y) (x>=0&&x<n&&y>=0&&y<m)

int main()
{
	int T;
	scanf("%d", &T);
	FOR (Case, T)
	{
		scanf("%d%d%d", &n, &m, &K);
		int ans = K;
		FOR (state, 1<<(n*m))
		{
			int tp = 0;
			int need = 0;
			FOR (i, n) FOR (j, m)
			{
				block[i][j] = (state>>(i*m+j))&1;
				if (block[i][j])
					need++;
				vis[i][j] = 0;
			}
			FOR (i, n) FOR (j, m)
			{
				if (vis[i][j])
				{
					continue;
				}
				vis[i][j] = 1;
				if (block[i][j])
				{
					tp++;
					continue;
				}
				queue<pii> q;
				q.push(mp(i, j));
				bool flag = 0;
				int cnt = 1;
				while (!q.empty())
				{
					pii p = q.front(); q.pop();
					int x = p.first, y = p.second;
					FOR (k, 4)
					{
						int nx = x+d[k][0], ny = y+d[k][1];
						if (isValid(nx, ny))
						{
							if (block[nx][ny]) continue;
							else if (!vis[nx][ny])
							{
								cnt++;
								vis[nx][ny] = 1;
								q.push(mp(nx, ny));
							}
						}
						else
							flag = 1;
					}
				}
				if (!flag)
					tp += cnt;
			}
			if (tp == K)
				ans = min(ans, need);
		}
		printf("Case #%d: %d\n", Case+1, ans);
	}
}
