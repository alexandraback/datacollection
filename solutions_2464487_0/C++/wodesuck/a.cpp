#include <stdio.h>
#include <cmath>

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		long long r, t;
		scanf("%lld%lld", &r, &t);
		long double x = -(2 * r - 1) * 0.25L +
			std::sqrt(0.25L * r * (r - 1) + 0.5L * t + 0.0625L);
		printf("Case #%d: %.0Lf\n", k, std::floor(x));
	}
}
