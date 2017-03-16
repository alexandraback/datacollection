#include<stdio.h>

int main() {
	int s[100][100];
	int t,n;
	int i, j,k;
	int a[1000] = { 0 }, b[1000] = { 0 }, c[500] = { 0 };
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		scanf("%d", &n);
		for (i = 0; i < 1000; i++) {
			a[i] = 0;
			b[i] = 0;
			if (i < 500) {
				c[i] = 0;
			}
		}
		for (i = 0; i < n*(2 * n - 1); i++) {
			scanf("%d", &j);
			if (j < 1000) {
				a[j]++;
			}
			else if (j < 2000) {
				b[j - 1000]++;
			}
			else {
				c[j - 2000]++;
			}
		}
		printf("Case #%d:", k + 1);
		for (i = 0; i < 1000; i++) {
			if (a[i] % 2 != 0) {
				printf(" %d", i);
			}
		}
		for (i = 0; i < 1000; i++) {
			if (b[i] % 2 != 0) {
				printf(" %d", i + 1000);
			}
		}
		for (i = 0; i < 500; i++) {
			if (c[i] % 2 != 0) {
				printf(" %d", i + 2000);
			}
		}
		printf("\n");
	}
}