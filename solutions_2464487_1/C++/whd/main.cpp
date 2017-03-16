/*
 * main.cpp
 *
 *  Created on: 2013-4-9
 *      Author: whd
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef long long big;
const big inf=1000000000000000000ll;
big r,t;
bool check(big x)
{
	double a=1.00*x*(2*r+2*x-1);
	if(a>inf)return false;
	return x*(2*r+x*2-1)<=t;
}
int main()
{
	int cass,cas;
	big s,e,mid;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	for(cass=1;cass<=cas;cass++)
	{
		cin>>r>>t;
		s=1;e=inf;
		while(s<=e)
		{
			mid=s+e>>1;
			if(check(mid))s=mid+1;
			else e=mid-1;
		}
		printf("Case #%d: %I64d\n",cass,e);
	}
	return 0;
}
