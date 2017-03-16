#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

long long gcd(long long a, long long b)
{
	while (a > 0)
	{
		b %= a;
		swap(a, b);
	}
	return b;
}

bool isPower(long long a)
{
	long long two = 1;
	while (two < a)
		two *= 2;
	return two == a;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int tt = 0; tt < t; tt++)
	{
		long long a, b;
		scanf("%lld/%lld", &a, &b);

		long long gc = gcd(a, b);
		a /= gc;
		b /= gc;

		if (!isPower(b))
		{
			printf("Case #%d: impossible\n", tt + 1);
		}
		else
		{
			int ans = 0;
			while (a < b)
				b /= 2, ans++;
			printf("Case #%d: %d\n", tt + 1, ans);
		}
	}

	return 0;
}