#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

bool check(int n, int *a, int m) {
	for (int st = 0; st < m; ++st) {
		int eattime = m - st;
		int restst = st;
		bool wrong = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > eattime) {
				if (restst == 0) { wrong = 1; break; }
				else {
					int need = (a[i] + eattime - 1) / eattime - 1;
					if (need > restst) { wrong = 1; break; }
					restst -= need;
				}
			}
		}
		if (restst >= 0 && !wrong){
			return 1;
		}
	}
	return 0;
}

int n;
int a[maxn];

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		scanf("%d", &n);
		int maximum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			maximum = max(maximum, a[i]);
		}

		int ans = -1;
		int l = 0, r = maximum;

		while (l <= r) {
			int m = (l + r) >> 1;
			if (check(n, a, m)) {
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
