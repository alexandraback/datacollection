// File Name: b.cpp
// Author: gonewithsin
// Created Time: 2013/4/27 10:19:05

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
int a[20];
int n, r, e;
int ans;

void dfs(int id,int en,int tmp)
{
	if(id > n)
	{
		ans = max(ans, tmp);
		return ;
	}
	for(int i = 0 ;i <= en; i++)
	{
		dfs(id + 1, min(e, en - i + r), tmp + i * a[id]);
	}

}

int main()
{
	int T;
	int cnt = 0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		cnt++;
		scanf("%d%d%d", &e, &r, &n);
		memset(a, 0, sizeof(a));
		for(int i=1;i<=n;i++)
			scanf("%d", &a[i]);
		ans = 0;
		dfs(1, e, 0);
		printf("Case #%d: %d\n", cnt, ans);
	}
    return 0;
}


