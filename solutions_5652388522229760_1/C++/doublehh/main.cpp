/*
*   Copyright (C) 2016 All rights reserved.
*   
*   filename: main.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2016-04-05 11:04:36
*   last modified: 2016-04-05 11:04:36
*/
#include <cstdio>
#include <iostream>
using namespace std;

long long n, t;

int vis[10];

void work()
{
	int t = ::t;
	while (t)
	{
		vis[t % 10] = true;
		t /= 10;
	}
}

void solve()
{
	if (n == 0)
	{
		cout << "INSOMNIA" << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
		vis[i] = false;
	t = n;
	for (;;)
	{
		work();
		bool ok = true;
		for (int i = 0; i < 10; i++)
			if (!vis[i])
				ok = false;
		if (ok) break;
		t += n;
	}
	cout << t << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		cin >> n;
		printf("Case #%d: ", i);
		solve();
	}
}
