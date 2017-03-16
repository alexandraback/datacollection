#include <cstdio>
typedef long long int LL;
int mul[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1},
};
int xmul(int a, int b)
{
	int rt = 1;
	if (a < 0) rt *= -1, a *= -1;
	if (b < 0) rt *= -1, b *= -1;
	rt *= mul[a][b];
	return rt;
}
int qpow(int a, LL n)
{
	int rt = 1, bs = a;
	while (n) {
		if (n & 1) rt = xmul(rt, bs);
		bs = xmul(bs, bs);
		n >>= 1;
	}
	return rt;
}
main()
{
	int t, l, ans, f[3], aj;
	long long int x;
	char s[10001];
	bool flag;
	scanf("%d", &t);
	for (int cs = 1 ; cs <= t ; ++cs) {
		ans = 1, f[0] = f[1] = f[2] = 0;
		scanf("%d%lld%s", &l, &x, s);
		for (int i = 0 ; i < l ; ++i) {
			f[s[i] - 'i'] = 1;
			ans = xmul(ans, s[i] - 'i' + 2);
		}
		if (f[0] + f[1] + f[2] < 2) {
			printf("Case #%d: NO\n", cs);
			continue;
		}
		ans = qpow(ans, x);
		if (ans != -1) {
			printf("Case #%d: NO\n", cs);
			continue;
		}
		flag = 0, x *= l, ans = 1;
		for (int i = 0 ; i < x ; ++i) {
			ans = xmul(ans, s[i % l] - 'i' + 2);
			if (ans == 2) {
				aj = 1;
				for (int j = i + 1 ; j < x ; ++j) {
					aj = xmul(aj, s[j % l] - 'i' + 2);
					if (aj == 3) {
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
		}
		printf("Case #%d: ", cs);
		puts(flag ? "YES" : "NO");
	}
}