// File Name: a.cpp
// Author: Missa
// Created Time: 2013/5/4 ÐÇÆÚÁù 23:52:31

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

const int inf = 0x3f3f3f3f;
const int maxn = 105;
LL a[maxn];
LL A, n;

int ans ;
void dfs(int i, int step)
{
	if (i >= n)
	{
		if (step < ans) ans = step;
	   	return;
	}
	if (A > a[i])
	{
		A += a[i];
		dfs(i + 1, step);
	}
	else
	{
		if ( n - i + step < ans) ans = step + n - i;
		if ( A == 1) return;
		while (A <= a[i])
		{
			A += A - 1;
			step ++;
		}
		A += a[i];
		dfs(i + 1,step);
	}
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%lld%lld",&A,&n);
		ans = inf;
		R(i,0,n) scanf("%lld",&a[i]);
		sort(a,a+n);
		dfs(0,0);
		printf("Case #%d: %d\n",cas,ans);
	}
    return 0;
}
