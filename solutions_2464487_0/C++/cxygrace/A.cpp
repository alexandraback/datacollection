#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long t, r;

long long calc(long long n)
{
	return 2 * n * n + (2 * r - 1) * n - t;
}

int main()
{
	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; i++)
	{
		scanf("%lld%lld", &r, &t);
		long double a = 2.0;
		long double b = 2 * r - 1;
		long double c = -t;
		long double delta = b * b - 4 * a * c;
		long double ans = (-b + sqrt(delta)) / (2 * a);
		printf("Case #%d: %lld\n", i, (long long)floor(ans));
	}
	return 0;
}
