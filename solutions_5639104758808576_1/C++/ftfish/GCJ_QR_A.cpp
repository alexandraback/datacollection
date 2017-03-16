#include <bits/stdc++.h>
using namespace std;
const int maxsm = 1010;

bool check(char *s, int sm, int m) {
	int c = m + s[0] - '0';
	for (int i = 1; i <= sm; ++i) {
		if (c < i) return 0;
		c += s[i] - '0';
	}
	return 1;
}

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		int sm;
		char s[maxsm];
		scanf("%d%s", &sm, s);

		int ans = -1;
		int l = 0, r = sm;

		while (l <= r) {
			int m = (l + r) >> 1;
			if (check(s, sm, m)) {
				ans = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		printf("Case #%d: ", Tn);
		printf("%d\n", ans);
	}
	return 0;
}
