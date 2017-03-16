#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <set>
#include <complex>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int v[10];
int e,r,n,ans;
void dfs(int idx,int total,int sum)
{
	if(idx==n) {ans=max(ans,sum); return;}
	for(int i=0;i<=total;i++)
	{
		dfs(idx+1,min(total-i+r,e),sum+v[idx]*i);
	}
}
int main()
{
	int cas;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		
		scanf("%d %d %d",&e,&r,&n);
		printf("Case #%d: ",cs);
		for(int i=0;i<n;i++) scanf("%d",v+i);
		ans=0;
		dfs(0,e,0);
		printf("%d\n",ans);
	}
}