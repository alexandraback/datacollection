/*
*   Copyright (C) 2016 All rights reserved.
*   
*   filename: main.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2016-04-05 11:04:36
*   last modified: 2016-04-05 11:04:36
*/
#include <bits/stdc++.h>
using namespace std;

long long k, c, s;

void solve()
{
	if (s * c < k)
	{
		puts(" IMPOSSIBLE");
		return;
	}
	int i = 0;
	while (s--)
	{
		long long t = 0;
		for (int j = 0; j < c; j++)
		{
			if (i < k)
				t = t * k + i++;
			else
				t *= k;
		}
		t++;
		printf(" %lld", t);
	}
	puts("");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		cin >> k >> c >> s;
		printf("Case #%d:", i);
		solve();
	}
}
