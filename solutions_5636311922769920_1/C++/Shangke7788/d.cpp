#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int K, C, S;
lint calc(int a) {
	lint ret = a, tt = 1;
	for (int i = 1; i < C; i++) {
		++a;
		if (a >= K) {
			a = K - 1;
		}
		tt *= K;
		ret += a * tt;
	}
	return ret + 1;
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
		printf("Case #%d:", ca);
		scanf("%d%d%d", &K, &C, &S);
		if (C == 1 && K != S) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		if (K > C * S) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < K; i += C) {
			printf(" %lld", calc(i));
		}
		printf("\n");
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
