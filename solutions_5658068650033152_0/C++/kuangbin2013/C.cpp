/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/11 18:34:21
File Name     :E:\2014ACM\±ÈÈü\2014_GCJ_R1C\C.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int n,m,k;
int a[100][100];
bool vis[22][22];
int Move[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int calc()
{
	int ret = 0;
	queue<pair<int,int> >q;
	memset(vis,false,sizeof(vis));
	for(int i = 0;i < n;i++)
	{
		if(a[i][0] == 0)
		{
			vis[i][0] = 1;
			q.push(make_pair(i,0));
		}
		if(a[i][m-1] == 0)
		{
			vis[i][m-1] = 1;
			q.push(make_pair(i,m-1));
		}
	}
	for(int j = 1;j < m-1;j++)
	{
		if(a[0][j] == 0)
		{
			vis[0][j] = 1;
			q.push(make_pair(0,j));
		}
		if(a[n-1][j] == 0)
		{
			vis[n-1][j] = 1;
			q.push(make_pair(n-1,j));
		}
	}
	while(!q.empty())
	{
		pair<int,int> tmp = q.front();
		q.pop();
		for(int i = 0;i < 4;i++)
		{
			int x = tmp.first + Move[i][0];
			int y = tmp.second + Move[i][1];
			if(x < 0 || y < 0 || x >= n || y >= m)
				continue;
			if(a[x][y])continue;
			if(vis[x][y])continue;
			vis[x][y] = 1;
			q.push(make_pair(x,y));
		}
	}
	ret = n*m;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if(vis[i][j])
				ret--;
	return ret;
}
int bit[30];

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	scanf("%d",&T);
	bit[0] = 1;
	for(int i = 1;i < 30;i++)
		bit[i] = bit[i-1]*2;
	while(T--)
	{
		iCase++;
		scanf("%d%d%d",&n,&m,&k);
		int tot = (1<<(n*m));
		int ans = n*m;
		for(int i = 0;i < tot;i++)
		{
			int cnt = 0;
			for(int j = 0;j < (n*m);j++)
			{
				if(i & bit[j])
				{
					cnt++;
					a[j/m][j%m] = 1;
				}
				else a[j/m][j%m] = 0;
			}
			if(calc() >= k)
				ans = min(ans,cnt);
		}
		printf("Case #%d: %d\n",iCase,ans);
	}
    return 0;
}
