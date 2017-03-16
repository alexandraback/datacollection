#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 1010

int seq[MAXN], a[MAXN], b[MAXN];

int cmp(int i, int j) {
	if (b[i] != b[j]) return b[i] < b[j];
	return a[i] < a[j];
}

int main() {
	int t, n, i, j, ca= 0, cur, tot, fail;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i=0;i<n;++i) {
			scanf("%d%d", &a[i], &b[i]);
			seq[i] = i;
		}
		sort(seq, seq+n,cmp);
		tot = 0;
		cur = fail = 0;
		for (i=0;i<n;++i) {
			while (cur < b[seq[i]]) {
				for (j=n-1;j>=0;--j) {
					if (a[seq[j]] >= 0 && a[seq[j]] <= cur) {
						cur ++;
						tot ++;
						a[seq[j]] = -1;
						break;
					}
				}
				if (j<0) {
					fail = true;
					break;
				}
			}
			if (fail) break;
			if (a[seq[i]] >= 0) cur += 2; else cur ++;
		}
		if (fail) {
			printf("Case #%d: Too Bad\n", ++ca);
		} else {
			printf("Case #%d: %d\n", ++ca, tot + n);
		}
	}
	return 0;
}