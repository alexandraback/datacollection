#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#define llu long long unsigned
#define ld long
#define F first
#define S second
#define ll long long
using namespace std;
#define si(x) scanf("%d",&x)
#define sdb(x) scanf("%lf",&x)
#define sll(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define pi(x) printf("%d", x);

int sum[200000];
int arr[1000];
int main()
{
	int t,co=1;
	si(t);
	while(t--)
	{
		int c,d,v,flag=0,temp,i,tp,ans=0,j;
		ll maxx;
		si(c);si(d);si(v);
		for(i=0;i<d;i++) si(arr[i]);
		for(i=0;i<=v;i++) sum[i]=0;
		maxx=1<<d;
		for(i=0;i<maxx;i++)
		{
			temp=i;
			tp=0;
			for(j=0;j<d;j++)
			{
				if(temp%2==1) tp+=arr[j];
				temp=temp/2;
			}
			sum[tp]=1;
		}
		for(i=1;i<=v;i++)
		{
			if(sum[i]!=1)
			{
				ans++;
				sum[i]=1;
				for(j=1;j<=v;j++)
				{
					if(sum[j]) sum[j+i]=1;
				}
			}
		}
		printf("Case #%d: %d\n",co++, ans);
	}
}

