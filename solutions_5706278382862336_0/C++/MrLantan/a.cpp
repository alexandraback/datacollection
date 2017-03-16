#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll gcd (ll a, ll b)
{
	while (a != 0 && b != 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int t;
	scanf ("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		ll p, q;
		scanf ("%lld/%lld", &p, &q);
		ll k = gcd (p, q);
		p /= k;
		q /= k;
		ll l = 0;
		while ((1ll << l) < q)
			l++;
		printf ("Case #%d: ", tt + 1);
		if ((1ll << l) != q)
			printf ("impossible\n");
		else
		{
			ll up = 1;
			while ((1ll << up) * p < q)
				up++;
			printf ("%lld\n", up);
		}
	}
	return 0;
}
