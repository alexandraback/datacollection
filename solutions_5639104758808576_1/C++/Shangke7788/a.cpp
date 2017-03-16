#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1010;
char s[MAX_N];
int n;

int main() {
#ifdef _SHANGKE_
	time_t _t1 = clock();
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
#endif
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d %s", &n, s);
		int sum = 0, ans = 0;
		for (int i = 0; i <= n; i++) {
			if (sum < i) {
				ans += i - sum;
				sum = i;
			}
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n", ca, ans);
	}
#ifdef _SHANGKE_
	fprintf(stderr, "%.3lf s\n", 1.0 * (clock() - _t1) / CLOCKS_PER_SEC);
#endif
	return 0;
}
