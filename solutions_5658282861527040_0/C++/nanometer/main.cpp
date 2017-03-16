#include <cstdio>
#include <cstdlib>

long a, b, k;

long solve() {
	long sum = 0;
	for (long i = 0; i < a; ++ i) {
		for (long j = 0; j < b; ++ j) {
			if ((i & j) < k) ++ sum;
		}
	}
	return sum;
}

int main(void) {
	int tests_count;
	scanf("%d", &tests_count);
	for (int test = 1; test <= tests_count; ++ test) {
		scanf("%ld%ld%ld", &a, &b, &k);
		long result = solve();
		printf("Case #%d: %ld\n", test, result);
	}
	return 0;
}
