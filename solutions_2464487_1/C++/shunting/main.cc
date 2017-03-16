#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

// 2 * l * l + l * (2r - 1) <= t
int 
main(void) {
	int T, seq;
	ull r, t;

	scanf("%d", &T);
	for (seq = 1; seq <= T; seq++) {
		scanf("%llu%llu", &r, &t);

		ull start = 0;
		ull end;
		ull mid;

		ull lim1 = (ull) sqrt((double) t);
		ull lim2 = t / (2 * r - 1);
		end = lim1;
		if (lim2 < end) {
			end = lim2;
		}
		while (start <= end) {
			mid = (start + end) / 2;
			if (2 * mid * mid + mid * (2 * r - 1) <= t) {
				start = mid + 1;
			} else {
			 	end = mid - 1;
			}
		}

		printf("Case #%d: %llu\n", seq, end);
	}
	return 0;
}
