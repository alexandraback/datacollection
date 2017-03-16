#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 300

int a[MAXN];

int main() {
	int t, ca= 0;
	int i, j, k, n, tot, ok;
	double need, l, r, m, p;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		tot = 0;
		for (i=0;i<n;++i) {
			scanf("%d", &a[i]);
			tot += a[i];
		}

		printf("Case #%d:", ++ca);
		for (i=0;i<n;++i) {
			l = 0;
			r = 1;
			while (r -l > 1e-8 ) {
				m = (l + r) / 2;
				p = tot * m + a[i];
				need = 0;
				ok = false;
				for (j=0;j<n;++j) {
					if (i==j) continue;
					if (p < a[j]) continue;
					need += (p-a[j]);
					ok = true;
				}
				if (ok && need + tot * m > tot) {
					r = m;
				} else {
					l = m;
				}
			}
			printf(" %.8lf", m * 100);
		}
		puts("");
		
	}
	return 0;
}