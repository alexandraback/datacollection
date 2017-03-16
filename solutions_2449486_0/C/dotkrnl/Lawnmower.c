/*       Jason Lau  -  Lawnmower       */
#include <stdio.h>

#define MAXN	100

void printStatus(int tcase);

int main(void) {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printStatus(i);
	return 0;
}

void upvalue(int *a, int b) {
	if (*a < b) *a = b;
}

int min(int a, int b) {
	return a > b ? b : a;
}

void printStatus(int tcase) {
	int data[MAXN][MAXN], flag = 1;
	int maxln[MAXN] = {0}, maxcol[MAXN] = {0};
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &data[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			upvalue(&maxln[i],  data[i][j]);
			upvalue(&maxcol[j], data[i][j]);
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (min(maxln[i], maxcol[j]) != data[i][j])
				flag = 0;
	printf("Case #%d: %s\n", tcase, flag ? "YES" : "NO");
}
