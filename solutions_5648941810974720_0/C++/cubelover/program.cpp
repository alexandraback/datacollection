#include <cstdio>

char *a[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char t[2222];
int d[222];

char *b = "ZXSGWUTVOI";
int c[10] = { 0, 6, 7, 8, 2, 4, 3, 5, 1, 9};

int r[10];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, tcn;
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		int i, j;
		scanf("%s", t);
		for (i = 0; t[i]; i++) d[t[i]]++;
		for (i = 0; i < 10; i++) {
			r[c[i]] = 0;
			while (d[b[i]]) {
				r[c[i]]++;
				for (j = 0; a[c[i]][j]; j++) d[a[c[i]][j]]--;
			}
		}
		printf("Case #%d: ", tc);
		for (i = 0; i < 10; i++) while (r[i]--) putchar(i + 48);
		putchar(10);
	}
	return 0;
}