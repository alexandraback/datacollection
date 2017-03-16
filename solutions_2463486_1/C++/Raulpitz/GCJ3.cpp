// GCJ3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include <math.h>
bool huiwen[10000001];
void init()
{
	int digits[20];
	int top;
	for(int i=0;i<=10000000;++i)
	{
		int tp = i;
		top = 0;
		while(tp!=0)
		{
			digits[top++] = tp%10;
			tp/=10;
		}
		int begin = 0, end = top-1;
		while(begin < end)
		{
			if(digits[begin++] != digits[end--]) {huiwen[i] = false; break;}
		}
		long long fang = (long long) i * (long long)i;
		long long tp2 = fang;
		top = 0;
		while(tp2!=0)
		{
			digits[top++] = tp2%10;
			tp2/=10;
		}
		begin = 0, end = top-1;
		while(begin < end)
		{
			if(digits[begin++] != digits[end--]) {huiwen[i] = false; break;}
		}
	}
}
int main()
{
	memset(huiwen,true,sizeof(huiwen));
	init();
	int T;
	long long from, to;
	freopen ( "C-large-1.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%lld%lld",&from,&to);
		

		double b = sqrt((long double)from);
		long long bb = (long long)b;
		long long org = bb*bb;
		if(org != from) bb+=1;
		double e = sqrt((long double)to);
		long long ee = (long long)e;
		int cnt =0;
		for(long long i=bb;i<=ee;++i)
		{
			if(huiwen[i])
			{
				++cnt;
			}
		}
		printf("Case #%d: %d\n",t,cnt);
	}
	return 0;
}

