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

int n, m;

void solve()
{
	if (s != k)
	{
		puts(" IMPOSSIBLE");
		return;
	}
	for (int i = 1; i <= k; i++)
		printf(" %d", i);
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
