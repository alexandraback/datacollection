#include <cstdio>
#include <cstdlib>
#include <cstring>

long a, b, k;
long dp[8][32];

long solve(long mask, long len) {
	long len0 = len - 1;
	if (len == 0) return mask == 7 ? 1 : 0;
	if (dp[mask][len] > -1) return dp[mask][len];
	long result = 0;
	for (int p = 0; p < 2; ++ p) {
		for (int q = 0; q < 2; ++ q) {
			if ((mask >> 0 & 1) == 0 && p > (a >> len0 & 1)) continue;
			if ((mask >> 1 & 1) == 0 && q > (b >> len0 & 1)) continue;
			long r = p & q;
			if ((mask >> 2 & 1) == 0 && r > (k >> len0 & 1)) continue;

			long mask0 = mask;
			if (p < (a >> len0 & 1)) mask0 |= 1;
			if (q < (b >> len0 & 1)) mask0 |= 2;
			if (r < (k >> len0 & 1)) mask0 |= 4;

			result += solve(mask0, len - 1);
		}
	}
	dp[mask][len] = result;
	return result;
}

int main(void) {
	int tests_count;
	scanf("%d", &tests_count);
	for (int test = 1; test <= tests_count; ++ test) {
		scanf("%ld%ld%ld", &a, &b, &k);
		memset(dp, -1, sizeof(dp));
		long result = solve(0, 32);
		printf("Case #%d: %ld\n", test, result);
	}
	return 0;
}
