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


int rev(int a)
{
	if(a%10==0) return 100000000;
	int ans=0;
	while(a)
	{
		ans=ans*10+a%10;
		a/=10;
	}
	return ans;
}

int dp[1001000];
int main()
{
	int i,n,t,id=1;
		for(i=1;i<10;i++) dp[i]=i;
		for(i=10;i<=1000100;i++)
		{
			if(rev(i)<i) dp[i]=min(dp[rev(i)],dp[i-1])+1;
			else dp[i]=dp[i-1]+1;
		}

	si(t);
	while(t--)
	{
		si(n);
		printf("Case #%d: %d\n",id++,dp[n]);
	}
	
}

