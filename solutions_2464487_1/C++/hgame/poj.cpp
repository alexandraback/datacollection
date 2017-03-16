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
const double pi=acos(-1.0);
const double eps=1e-8;
int main()
{
	int cas;
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&cas);
	long long r,t;
	for(int cs=1;cs<=cas;cs++)
	{
		long long mn=1,mx=1ll<<32;
		scanf("%I64d %I64d",&r,&t);
		printf("Case #%d: ",cs);
		while(mn<=mx)
		{
			long long mid=mn+mx>>1;
			double sum=mid+(r+r+2*(mid-1))*double(mid);
			if(sum<=t+eps) mn=mid+1;
			else mx=mid-1;
		}
		printf("%I64d\n",mn-1);
	}
}