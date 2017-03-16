#include <stdio.h>
#include <cmath>

bool chk(long long n, long long r, long long t)
{
	return 2 * n * r <= t - (2 * n - 1) * n;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		long long r, t;
		scanf("%lld%lld", &r, &t);
		long long n = std::floor(-(2 * r - 1) * 0.25L +
			std::sqrt(0.25L * r * (r - 1) + 0.5L * t + 0.0625L));
		while (!chk(n, r, t)) --n;
		printf("Case #%d: %lld\n", k, n);
	}
}
