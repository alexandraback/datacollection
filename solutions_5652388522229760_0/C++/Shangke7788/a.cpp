#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

lint gao(int x) {
	int a[10] = {0}, has = 0;
	lint ret = -1LL;
	for (int i = 1; has < 10 && i <= 1000000; i++) {
		ret = 1LL * x * i;
		lint tmp = ret;
		while (tmp != 0LL) {
			int t = tmp % 10;
			if (a[t] == 0) {
				++has;
				++a[t];
			}
			tmp /= 10;
		}
	}
	if (has) {
		return ret;
	} else {
		return -1LL;
	}
}

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		printf("Case #%d: ", ca);
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("INSOMNIA\n");
		} else {
			printf("%lld\n", gao(n));
		}
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
