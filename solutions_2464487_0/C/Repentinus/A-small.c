#include <stdio.h>

long long solve1(long long r, long long t)
{
	long long ret = 0;
	for (; 2 * r + 1 <= t; r += 2) {
		t -= 2 * r + 1;
		++ret;
	}
	return ret;
}

int main(int const argc, char const* const* argv)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		long long r = 0, t = 0;
		scanf("%lld %lld", &r, &t);
		printf("Case #%d: %lld\n", (i + 1), solve1(r, t));
	}
	return 0;
}
