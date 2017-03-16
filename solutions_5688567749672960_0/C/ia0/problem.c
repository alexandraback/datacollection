#include <assert.h>
#include <stdio.h>
#include <string.h>

static long int pow[15] = {
	1l,
	10l,
	100l,
	1000l,
	10000l,
	100000l,
	1000000l,
	10000000l,
	100000000l,
	1000000000l,
	10000000000l,
	100000000000l,
	1000000000000l,
	10000000000000l,
	100000000000000l
};

static long int dec(int n)
{
	long int R = 0;
	while (--n > 1) {
		int k = n / 2, r = n % 2;
		R += pow[k + r] + pow[k] - 1;
	}
	return R + 9;
}

static long int solve(char *N)
{
	int n = (int)strlen(N);
	assert(n > 0);
	if (n == 1) return N[0] - '0';
	long int L = 0, H = 0;
	int k = n / 2;
	for (int i = k; i < n; i++) {
		L *= 10;
		L += N[i] - '0';
	}
	for (int i = k - 1; i >= 0; i--) {
		H *= 10;
		H += N[i] - '0';
	}
	return L + H + (H != 1) + dec(n);
}

int main(void) {
	int T_;
	assert(scanf("%d", &T_) == 1);
	for (int t_ = 1; t_ <= T_; t_++) {
		char N[15];
		assert(scanf("%s", N) == 1);
		printf("Case #%d: %ld\n", t_, solve(N));
	}
	return 0;
}
