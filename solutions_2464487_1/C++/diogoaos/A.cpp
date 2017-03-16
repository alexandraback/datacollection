#include <cstdio>

typedef long long lint;

const lint INF = 1000000000LL;
lint r, t;

lint calc(lint mid) {
	if (2*mid > t / r) {
		return t + 1;
	}
	
	if (2 * mid * r + 2 * mid * (mid - 1) + mid < 0) {
		return t + 1;
	}

	return 2 * mid * r + 2 * mid * (mid - 1) + mid;
}

int main() {
	int ntests;
	
	scanf("%d", &ntests);
	
	for (int test = 1; test <= ntests; test++) {
		printf("Case #%d: ", test);
		scanf("%I64d %I64d", &r, &t);
		
		lint bot = 0, top = INF;
		lint ans = 0;
		
		while (bot <= top) {
			lint mid = (bot + top) / 2;
			
			if (calc(mid) <= t) {
				ans = mid;
				bot = mid + 1;
			} else {
				top = mid - 1;
			}
		}
		
		printf("%I64d\n", ans);
	}

	return 0;
}
