// GCJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <math.h>
#include <cstdio>
#include <iostream>
#define PI 3.14159265358

int main()
{
	int T;
	double r,t;
	double marea;
	freopen ( "A-small-attempt0.in", "r", stdin );
	freopen ( "out.out", "w",stdout);
	scanf("%d",&T);
	for(int xx=1;xx<=T;++xx)
	{
		scanf("%lf%lf",&r,&t);
		double tp = (r-0.5);
		tp /= 2;
		double n = sqrt((double)t/2 + tp*tp) -tp;
		printf("Case #%d: ", xx);
		long long out = (long long)n;
		printf("%lld\n",out);
	}
	return 0;
}

