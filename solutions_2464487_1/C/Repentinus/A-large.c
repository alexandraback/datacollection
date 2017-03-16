#include <stdio.h>
#include <math.h>
#include <quadmath.h>

long long solve1(long long r, long long t)
{
	long long ret = 0;
	for (; 2 * r + 1 <= t; r += 2) {
		t -= 2 * r + 1;
		++ret;
	}
	return ret;
}

long long solve2(long long r, long long t)
{
	__float128 rr = r, tt = t;
	__float128 a = (-2 * rr - 3 + sqrtq(4 * rr * rr - 4 * rr + 1 + 8 * tt)) / 4;
	//printf("%Lf %lld\n", a, (long long)a);
	return (long long)a + 1;
}

int main(int const argc, char const* const* argv)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		long long r = 0, t = 0;
		scanf("%lld %lld", &r, &t);
		printf("Case #%d: %lld\n", (i + 1), solve2(r, t));
	}
	return 0;
}
