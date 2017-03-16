#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

char s[101010];
int gao(char *s) {
	int n = strlen(s);
	int ret = 0;
	for (int i = 1; i < n; i++) {
		ret += s[i] != s[i - 1];
	}
	ret += s[n - 1] != '+';
	return ret;
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
		scanf("%s", s);
		printf("%d\n", gao(s));
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
