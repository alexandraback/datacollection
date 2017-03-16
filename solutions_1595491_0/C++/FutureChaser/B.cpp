#include <stdio.h>

const int MAXN = 110;

int n, s, p;
int a[MAXN];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int k = 0; k < cases; ++k) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] % 3 == 0) {
				if (a[i] / 3 >= p) {
					++ans;
				} else if ((a[i] > 0) && (a[i] / 3 + 1 >= p) && (s > 0)) {
					++ans;
					--s;
				}
			} else if (a[i] % 3 == 1) {
				if (a[i] / 3 + 1 >= p) ++ans;
			} else {
				if (a[i] / 3 + 1 >= p) {
					++ans;
				} else if ((a[i] / 3 + 2 >= p) && (s > 0)) {
					++ans;
					--s;
				}
			}
		}
		printf("Case #%d: %d\n", k + 1, ans);
	}
	return 0;
}
