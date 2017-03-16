#include <cstdio>
#include <cstdlib>
#include <algorithm>

char buf[1024 * 1024 * 10];

// i = 2, j = 3, k = 4
int m[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int multi(int a, int b);

int qpow(int a, long e)
{
	if (e == 0) return 1;
	if (e == 1) return a;
	if (e == 2) return multi(a, a);
	if (e == 3) return multi(multi(a, a), a);

	// e >= 4
	return qpow(a, e % 4L);
}

int multi(int a, int b)
{
	int sign_a = (a < 0) ? -1 : 1;
	int sign_b = (b < 0) ? -1 : 1;
	return sign_a * sign_b * m[a * sign_a][b * sign_b];
}

int solve(long l, long x)
{
	if (l * x < 3L) return 0;

	int v = 1;
	for (int i = 0; i < l; i++) {
		// printf("%d: %d * %d = %d\n", i, v, buf[i], multi(v, buf[i]));
		v = multi(v, buf[i]);
	}
	if (qpow(v, x) != multi(multi(2, 3), 4)) return 0;

	// can we get an i?
	int prefix = 1;
	long i_bound = std::min(4L * l, x * l - 1L);
	// printf("ib: %ld\n", i_bound);
	long i;
	for (i = 0; i < i_bound; i++) {
		prefix = multi(prefix, buf[i % l]);
		if (prefix == 2) break;
	}
	if (prefix != 2) return 0;

	int postfix = 1;
	long k_bound = std::max(x * l - 4L * l, 2L);
	// printf("kb: %ld\n", k_bound);
	
	long k;
	for (k = x * l - 1; k >= k_bound; k--) {
		postfix = multi(buf[k % l], postfix);
		if (postfix == 4) break;
	}
	if (postfix != 4) return 0;

	return (i < k);
}

int main()
{
	int t_max;
	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		long l, x;

		scanf("%ld %ld\n%s", &l, &x, buf);
		for (long i = 0; i < l; i++) {
			buf[i] -= ('i' - 2);
		}
		// printf("%d: %ld %ld\n", t, l, x);
		printf("Case #%d: %s\n", t, solve(l, x) ? "YES" : "NO");
	}
}