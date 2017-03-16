/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: d.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-04-12
*   last modified: 2014-04-12 08:52:25
*/
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)

const int maxn = 1000;
int n;
double a1[maxn], a2[maxn];
set<double> S;

int main()
{
	//freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR1 (Case, T)
	{
		scanf("%d", &n);
		FOR (i, n)
			scanf("%lf", a1+i);
		sort(a1, a1+n);
		FOR (i, n)
			scanf("%lf", a2+i);
		sort(a2, a2+n);
		printf("Case #%d:", Case);
		int ans1 = 0;
		for (int i1 = 0, i2 = n-1, j1 = 0, j2 = n-1; i1 <= i2; )
		{
			if (a1[i1] > a2[j1])
			{
				i1++, j1++;
				ans1++;
			}
			else
				i1++, j2--;
		}
		printf(" %d", ans1);
		int ans2 = 0;
		S.clear();
		FOR (i, n)
			S.insert(a2[i]);
		FOR (i, n)
		{
			if (S.lower_bound(a1[i]) == S.end())
			{
				ans2++;
				S.erase(S.begin());
			}
			else
				S.erase(S.lower_bound(a1[i]));
		}
		printf(" %d\n", ans2);
	}
}
