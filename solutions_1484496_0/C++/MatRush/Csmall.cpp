#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 22;
int a[MAXN];

int sum[MAXN];
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int cas, n, T = 0;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		printf("Case #%d:\n", ++T);
		bool over = false;
		for (int i = 0; i < (1 << n); i++) {
			if (over) break;
			for (int sub = i; sub; sub = (sub - 1) & i) {
				int nsub = i & ~sub, sum1 = 0, sum2 = 0;
				for (int j = 0; j < n; j++) {
					if (sub & (1 << j)) {
						sum1 += a[j];
					}
					if (nsub & (1 << j)) {
						sum2 += a[j];
					}
				}
				if (sum1 == sum2) {
					int t = 0;
					for (int j = 0; j < n; j++) {
						if (sub & (1 << j)) {
							if (t++) putchar(' ');
							printf("%d", a[j]);
						}
					}
					puts("");
					t = 0;
					for (int j = 0; j < n; j++) {
						if (nsub & (1 << j)) {
							if (t++) putchar(' ');
							printf("%d", a[j]);
						}
					}
					puts("");
					over = true;
					break;
				}
			}
		}
	}
}
