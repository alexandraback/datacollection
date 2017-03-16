/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: b.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-04-12
*   last modified: 2014-04-12 07:14:32
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)

double c, f, x;

void init()
{
	scanf("%lf%lf%lf", &c, &f, &x);
}
double solve()
{
	double t = 0, curf = 2.0;
	for (;;)
	{
		if (x/curf > c/curf + x/(curf+f) + 1e-12)
		{
			t += c/curf;
			curf += f;
		}
		else
		{
			t += x/curf;
			break;
		}
	}
	return t;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR1 (Case, T)
	{
		init();
		printf("Case #%d: %.7lf\n", Case, solve());
	}
}
