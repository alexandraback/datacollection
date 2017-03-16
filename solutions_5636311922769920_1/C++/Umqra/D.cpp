#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

ll getNumber(vector <ll> d, ll base)
{
	ll value = 0;
	for (ll x : d)
	{
		value *= base;
		value += x;
	}
	return value + 1;
}

void solve(ll k, ll c, ll s)
{
	if (s * c < k)
	{
		puts("IMPOSSIBLE");
		return;
	}
	for (int i = 0; i < k; i += c)
	{
		vector <ll> d = {};
		for (int a = 0; a < c; a++)
			d.push_back((i + a) % k);
		printf("%lld ", getNumber(d, k));
	}
	puts("");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		ll k, c, s;
		scanf("%lld%lld%lld", &k, &c, &s);
		printf("Case #%d: ", i + 1);
		solve(k, c, s);
	}

	return 0;
}
