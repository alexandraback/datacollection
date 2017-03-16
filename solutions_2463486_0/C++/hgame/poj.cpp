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
int a[10000000];
int b[14];
int a_sz=0;
int solve(long long num)
{
	int mx=a_sz-1,mn=0,mid;
	while(mn<=mx)
	{
		mid=mx+mn>>1;
		long long tmp=(long long)a[mid]*a[mid];
		if(tmp<=num) mn=mid+1;
		else mx=mid-1;
	}
	return mn;
}
bool check(long long tmp)
{
	int l=0;
	while(tmp) {b[l++]=tmp%10; tmp/=10;}
	for(int j=0;j<l/2;j++)
	{
		if(b[j]!=b[l-1-j]) return 0;
	}
	return 1;
}
int main()
{
	int cas;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for(long long i=0;i<=9999999;i++)
	{
		if(check(i)&&check(i*i)) a[a_sz++]=i;
	}
	scanf("%d",&cas);
	long long a1,a2;
	for(int cs=1;cs<=cas;cs++)
	{
		scanf("%I64d %I64d",&a1,&a2);
		printf("Case #%d: ",cs);
		printf("%d\n",solve(a2)-solve(a1-1));
	}
}