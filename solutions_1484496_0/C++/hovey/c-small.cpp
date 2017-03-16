#include <stdio.h>
int n;
int A[510], mrk[510];

int find(int step, int a, int b) {
	if (step >= n) {
		return false;
	}
	int i, j, k;
	if (a == b && a > 0) {
		for (k=1;k<=2;++k) {
			j = 0;
			for (i=0;i<step;++i) {
				if (mrk[i] == k) {
					if (j == 0) j = 1; else printf(" ");
					printf("%d", A[i]);
				}
			}
			puts("");
		}
		return true;
	}
	mrk[step] = 1;
	if (find(step+1, a + A[step], b)) return true;
	mrk[step] = 2;
	if (find(step+1, a, b + A[step])) return true;
	mrk[step] = 0;
	return (find(step+1, a, b));
}

int main() {
	int t, ca= 0;
	int i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i=0;i<n;++i) scanf("%d", &A[i]);
		printf("Case #%d:\n", ++ca);
		if (!find(0, 0, 0)) {
			puts("Impossible");
		}
	}
	return 0;
}