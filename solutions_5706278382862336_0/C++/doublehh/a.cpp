/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: a.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-05-11
*   last modified: 2014-05-11 17:21:29
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define foreach(it, s) for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++)

int main()
{
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	LL p, q;
	char ch;
	FOR (Case, T)
	{
		cin >> p >> ch >> q;
		LL g = __gcd(p, q);
		p /= g, q /= g;
		int ans = -1;
		FOR (i, 41)
		{
			LL tp = 1LL << i;
			if (tp % q == 0)
			{
				ans = 1;
				break;
			}
		}
		if (ans == 1)
		{
			FOR (i, 41)
			{
				LL tp = 1LL << i;
				if (tp * p >= q)
				{
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: ", Case+1);
		if (ans == -1) puts("impossible");
		else printf("%d\n", ans);
	}
}
