#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		ll g = gcd(a, b);
		a /= g;
		b /= g;
		if ((b & (b - 1)) != 0)
		{
			printf("Case #%d: impossible\n", i + 1);
			continue;
		}
		int t = 1;
		while (1)
		{
			if (b / 2 <= a)
				break;
			else
				b /= 2;
			t++;
		}
		printf("Case #%d: %d\n", i + 1, t);
	}
	return 0;
}