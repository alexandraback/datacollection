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


int size(ll a)
{
	int ans=0;
	while(a)
	{
		ans+=1;
		a/=10;
	}
	return ans;
}
ll rev(ll a)
{
	ll ans=0;
	while(a)
	{
		ans=ans*10+a%10;
		a/=10;
	}
	return ans;
}
ll solve(ll a)
{
	if(a<10) return a;
	int sz=size(a);
	ll pro=1,ans=0,temp2;
	int temp=(sz+1)/2,i;
	for(i=0;i<temp;i++) pro=10*pro;
	// printf("%lld\n", pro);
	temp2=rev(a/pro);
	if(temp2==1) ans=a%pro+9;
	else
	{
		if(a%pro==0) return 1+solve(a-1);
		ans=a%pro+temp2+9;
	} 
	for(i=temp;i<sz-1;i++) pro*=10;
	pro-=9;
	return ans+solve(pro);
}
int main()
{
	ll n;
	int t,id=1;
	si(t);
	while(t--)
	{
		sll(n);
		printf("Case #%d: %lld\n",id++,solve(n));
	}
	return 0;
}
	
		

