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

const int maxn = 1e8, maxm = 1e7;
bool flag[maxn];
int prime[maxm], cnt;

void gen_prime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (!flag[i]) prime[cnt++] = i;
		for (int j = 0; j < cnt; j++)
		{
			if (1LL * prime[j] * i >= maxn) break;
			flag[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int n, m;

void solve()
{
	for (long long i = (1LL << (n - 1)) + 1; ; i += 2) {
		bool ok = true;
		for (int b = 2; b <= 10; b++) {
			bool is_prime = true;
			for (int j = 0; j < 10; j++)
			{
				long long t = 0;
				for (int k = n - 1; k >= 0; k--)
					t = (1LL * t * b + (i >> k & 1)) % prime[j];
				if (t == 0)
				{
					is_prime = false;
					break;
				}
			}
			if (is_prime)  {
				ok = false;
				break;
			}
		}
		if (!ok) continue;
		for (int j = n - 1; j >= 0; j--)
			printf("%d", int(i >> j & 1));
		for (int b = 2; b <= 10; b++) {
			for (int j = 0; j < 10; j++)
			{
				long long t = 0;
				for (int k = n - 1; k >= 0; k--)
					t = (1LL * t * b + (i >> k & 1)) % prime[j];
				if (t == 0)
				{
					printf(" %d", prime[j]);
					break;
				}
			}
		}
		puts("");
		if (--m == 0) break;
	}
}

int main()
{
	gen_prime();
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", i);
		solve();
	}
}
