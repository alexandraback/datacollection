/*
 * c.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: AhmedHamza
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
ll arr[10000001];
int sz;
inline bool isPal(ll x)
{
	string s;
	while (x)
	{
		s.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < (int) s.size() / 2; ++i)
		if (s[i] != s[s.size() - i - 1])
			return 0;
	return 1;
}
int main()
{
	freopen("C-small-attempt0.in", "rt", stdin);
		freopen("c.out1", "wt", stdout);
	ll x;
	for (ll i = 1; i <= 10000000; ++i)
	{
		if (!isPal(i))
			continue;
		x = i * i;
		if (isPal(x))
			arr[sz++] = x;
	}
//	for (int i = 0; i < sz; ++i)
//		fprintf(stderr, "%I64d\n", arr[i]);
//	fprintf(stderr, "%d\n", sz);

	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		ll a, b;
		int c = 0;
		scanf("%I64d%I64d", &a, &b);
		for (int i = 0; i < sz; ++i)
			if (arr[i] >= a && arr[i] <= b)
				c++;
		printf("Case #%d: %d\n", T, c);
	}

	return 0;
}
