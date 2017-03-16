//Time:4/14/2012
//Author:PiAnte28
//Language:C++
//For Google Code Jam Recycled Numbers
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int num[10];
int jl[10];
int tt,hehe,da,db;

bool check(int x,int y)
{
    for (int i=1;i<=y;i++)
	if (jl[i]==x) return false;
	return true;
}

int main()
{
    freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
	scanf("%d %d\n",&da,&db);
	int ws(0),p(da),ans(0);
	while (p) {ws++;p/=10;}
	for (int i=da;i<=db-1;i++)
	{
	    int p(i),jll(0);
		memset(jl,0,sizeof(jl));
		for (int j=ws;j>=1;j--) {num[j]=p%10;p/=10;}
		for (int j=2;j<=ws;j++)
		{
		    int temp(0);
			for (int k=j;k<=ws;k++) temp=temp*10+num[k];
			for (int k=1;k<=j-1;k++) temp=temp*10+num[k];
			if (temp>i && temp<=db && check(temp,jll)) {ans++;jll++;jl[jll]=temp;}
		}
	}
	printf("Case #%d: %d\n",hehe-tt,ans);
	}
	return 0;
}
