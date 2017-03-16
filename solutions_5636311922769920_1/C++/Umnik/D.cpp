#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll k, c;
int s;

ll getNum(ll x)
{
	ll res = 0;
	for (int i = 0; i < c; i++)
		res = res * k + min(k - 1, x + i);
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int it = 0; it < t; it++)
	{
		scanf("%lld%lld%d", &k, &c, &s);
		printf("Case #%d:", it + 1);
		if (c * s < k)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < k; i += c)
			printf(" %lld", 1 + getNum(i));
		printf("\n");
	}

	return 0;
}