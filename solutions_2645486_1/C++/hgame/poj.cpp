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
int v[10000],mx[10000];
int e,r,n;
int main()
{
	int cas;
	freopen("B-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(int cs=1;cs<=cas;cs++)
	{
		scanf("%d %d %d",&e,&r,&n);
		r=min(r,e);
		printf("Case #%d: ",cs);
		for(int i=0;i<n;i++) scanf("%d",v+i);
		mx[n-1]=v[n-1];
		for(int i=n-2;i>=0;i--) mx[i]=max(v[i],mx[i+1]);
		long long now=e;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			if(mx[i]==v[i])
			{
				ans+=v[i]*now;
				now=r;
			}
			else
			{
				now+=r;
				if(now>e)
				{
					ans+=(now-e)*v[i];
					now=e;
				}
			}
		}
		printf("%I64d\n",ans);
	}
}