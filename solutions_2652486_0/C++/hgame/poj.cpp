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
bool f[126];
int s[7],a[3];
int r,n,m,k;
bool dfs(int idx)
{
	if(idx==n)
	{
		memset(f,0,sizeof(f));
		for(int h=0;h<1<<n;h++)
		{
			int p=1;
			for(int h1=0;h1<n;h1++)
			{
				if(1<<h1&h) p*=a[h1];
			}
			f[p]=1;
		}
		for(int i=0;i<k;i++)
		{
			if(!f[s[i]]) return 0;
		}
		return 1;
	}
	for(int i=2;i<=m;i++)
	{
		a[idx]=i;
		if(dfs(idx+1)) return 1;
	}
	return 0;
}
int main()
{
	int cas;
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		scanf("%d %d %d %d",&r,&n,&m,&k);
		printf("Case #%d: \n",cs);
		while(r--)
		{
			for(int i=0;i<k;i++) scanf("%d",s+i);
			if(dfs(0))
			{
				for(int i=0;i<n;i++) printf("%d",a[i]);
				putchar('\n');
			}
			else
			{
				for(int i=0;i<n;i++) printf("2",a[i]);
				putchar('\n');
			}
		}	
	}
}