#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
#define mp make_pair

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll p[45];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	p[0] = 1;
	for (int i = 1; i < 55; i++)
		p[i] = p[i - 1] * 2;
	for (int q = 0; q < tests; q++)
	{
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		ll g = gcd(a, b);
		a /= g;
		b /= g;
		printf("Case #%d: ", q + 1);
		bool found = 0;
		for (int i = 0; i < 55; i++)
		{
			if (b == p[i])
			{
				found = 1;
			}
		}
		if (!found)
		{
			printf("impossible\n");
			continue;
		}

		found = 0;
		int ans = 400;
		for (int i = 0; i < 55; i++)
		{
			ll d;
			d = max(p[i], b);
			ll cur_a = a * (d / b);
			ll cur1 = 1 * (d / p[i]);
			if (cur_a >= cur1)
			{
				ans = i;
				break;
			}
		}
		if (ans <= 40)
			printf("%d", ans);
		else
			printf("impossible");
		printf("\n");
	}
	return 0;
}