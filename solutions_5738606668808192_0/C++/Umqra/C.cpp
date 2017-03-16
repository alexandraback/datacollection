#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef __int128 kek;

kek Mod;

kek gen()
{
	return rand() % Mod;
}

set <kek> used;

kek dig[100];

void getRepr(int len, kek value)
{
	for (int i = 0; i < len; i++)
	{
		dig[i] = value % 2;
		value /= 2;
	}
}

kek getDiv(int len, kek base)
{
	kek number = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		number *= base;
		number += dig[i];
	}
	for (kek d = 2; d <= 200; d++)
	{
		if (number % d == 0)
			return d;
	}
	return -1;
}

kek divisor[100];

bool check(int len, kek value)
{
	getRepr(len, value);
	for (int i = 2; i <= 10; i++)
	{
		divisor[i] = getDiv(len, i);
		if (divisor[i] == -1)
			return false;
	}
	return true;
}

void solve(int n, int k)
{
	used.clear();

	Mod = ((kek)1 << (kek)(n - 2));
	while (k > 0)
	{
		kek r = gen() * 2 + 1 + ((kek)1 << (kek)(n - 1));
		if (used.count(r) > 0)
			continue;
		if (check(n, r))
		{
			for (int s = n - 1; s >= 0; s--)
				printf("%d", (int)dig[s]);
			for (int s = 2; s <= 10; s++)
				printf(" %d", (int)divisor[s]);
			puts("");
			k--;
		}
		used.insert(r);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("Case #%d:\n", i + 1);
		solve(n, k);
	}
	return 0;
}
