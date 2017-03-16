// File Name: c.cpp
// Author: Missa
// Created Time: 2013/4/13 ÐÇÆÚÁù 23:13:00

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
#define CL(x,v) memset(x,v,sizeof(x));
#define R(i,st,en) for(int i=st;i<en;++i)
#define LL long long
#define inf 0x3f3f3f3f

const int maxn = 101;
int a[maxn][maxn];
bool vis[maxn][maxn];
int n,m;
struct node
{
	int x,y,h;
	node(){}
	node(int x, int y, int h):x(x), y(y), h(h){}
	bool operator < (const node & oth) const
	{
		return h < oth.h;
	}
};

bool check(node cur)
{
	int x = cur.x;
	int y = cur.y;
	int h = cur.h;
	bool row = true, col = true;
	for (int i = 1; i <= m; ++i)
	{
		if (vis[x][i] && a[x][i] > h)
			row = false;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i][y] && a[i][y] > h)
			col = false;
	}
	if (row == false && col == false) return false;
	if (row)
	{
		for (int i = 1; i <= m; ++i)
			a[x][i] = h;
		return true;
	}
	for (int i = 1; i <= n; ++i)
			a[i][y] = h;
	return true;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int cas = 1; cas <= t; ++cas)
	{
		for (int i = 0; i < maxn; ++i)	
			for (int j = 0; j < maxn; ++j)
				a[i][j] = maxn;
		memset(vis, 0, sizeof(vis));
		bool ok = true;
		scanf("%d%d",&n,&m);
		priority_queue<node>q;
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				int h;
				scanf("%d", &h);
				q.push(node(i, j, h));
			}
		while (!q.empty())
		{
			node cur = q.top();q.pop();
			if (check(cur) == false)
			{
				ok = false;
				break;
			}
			vis[cur.x][cur.y] = 1;
		}
		printf("Case #%d: ",cas);
		if (ok) puts("YES");
		else puts("NO");

	}
    return 0;
}
