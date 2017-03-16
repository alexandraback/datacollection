// GCJ3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include <math.h>
bool huiwen[10000001];
void init()
{
	int digits[10];
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
	}
}
int main()
{
	memset(huiwen,true,sizeof(huiwen));
	init();
	int T;
	long long from, to;
	freopen ( "C-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%lld%lld",&from,&to);
		

		//double b = sqrt((long double)from);
		long long bb = (long long)from;
		//double e = sqrt((long double)to);
		long long ee = (long long)to;
		int cnt =0;
		for(int i=bb;i<=ee;++i)
		{
			if(huiwen[i])
			{
				int ss = sqrt((double)i);
				if(ss * ss == i && huiwen[ss])
				++cnt;
			}
		}
		printf("Case #%d: %d\n",t,cnt);
	}
	return 0;
}

