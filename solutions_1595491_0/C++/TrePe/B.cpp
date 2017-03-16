#include <stdio.h>

int i, j, k, cnt;
int n, N, S, p;
int a[100];
int sur[31];
int nsur[31];

int main() {
	for (i = 0; i <= 10; i++) {
		for (j = i; j <= 10 && j <= i + 2; j++) {
			for (k = j; k <= 10 && k <= i + 2; k++) {
				if (k == i + 2) sur[i+j+k] = k;
				else nsur[i+j+k] = k;
			}
		}
	}

	scanf("%d", &n);
	for (int kejs = 1; kejs <= n; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d%d", &N, &S, &p);
		for (i = 0; i < N; i++) scanf("%d", &a[i]);
		for (j = 0; j < N; j++) for (i = 1; i < N; i++) if (a[i-1] > a[i]) {k = a[i-1]; a[i-1] = a[i]; a[i] = k;}
		cnt = 0;
		for (i = 0; i < N; i++) {
			if (nsur[a[i]] >= p) cnt++;
			else {
				if (sur[a[i]] >= p && S > 0) {
					cnt++;
					S--;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
