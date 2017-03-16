#include <iostream>
#include <vector>

using namespace std;

typedef long long lli;

lli GCD(lli a, lli b)
{
	while (a > 0)
	{
		if (a < b)
			swap(a, b);
		a %= b;
	}
	return b;
}

struct f
{
	lli nom, denom;
	f(lli a, lli b)
	{
		lli gcd = GCD(a, b);
		nom = a / gcd;
		denom = b / gcd;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		lli a, b;
		scanf("%lld/%lld", &a, &b);
		lli gcd = GCD(a, b);
		a /= gcd;
		b /= gcd;
		int ans = -1;
		for (int i = 0; i <= 40; i++)
		{
			lli r = 1LL << i;
			if (b == r)
				ans = i;
		}
		if (ans != -1)
		{
			while (a > 0)
			{
				ans--;
				a >>= 1;
			}

			printf("Case #%d: %d\n", t + 1, ans + 1);
		} else
		{
			printf("Case #%d: impossible\n", t + 1);
		}
	}
	
}