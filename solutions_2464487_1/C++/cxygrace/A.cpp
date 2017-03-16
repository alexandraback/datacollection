#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long t, r;

long long calc(long long n)
{
	return 2 * n * n + (2 * r - 1) * n - t;
}

long long searchans()
{
	long long left = 0, right = min(2000000000LL, t / (2 * r - 1) + 1);
	while (left + 1 < right)
	{
		long long mid = (left + right) / 2;
		if (calc(mid) <= 0) left = mid; else right = mid;
	}
	return left;
}

int main()
{
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; i++)
	{
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: %lld\n", i, searchans());
	}
	return 0;
}
