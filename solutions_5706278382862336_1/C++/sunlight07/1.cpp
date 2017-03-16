#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return gcd(a % b, b);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++)
	{
		long long a, b;
		scanf("%lld/%lld", &a, &b);
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		if ((b & (b - 1)) != 0)
		{
			printf("Case #%d: impossible\n", t);
		} else {
			int result = 0;
			while (a < b)
			{
				a *= 2;
				result++;
			}
			printf("Case #%d: %d\n", t, result);
		}
	}
	return 0;
}
