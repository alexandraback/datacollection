#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 32

int v[N + 1], tot;

int fair(char s[])
{
	int i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		if (s[i] != s[j])
			return 0;
	return 1;
}

void init(void)
{
	char st[10];
	int i, j;

	for (i = 1; i <= N; i++) {
		itoa(i, st, 10);
		if (fair(st)) {
			itoa(j = i * i, st, 10);
			if (fair(st))
				v[tot++] = j;
		}
	}
}

int find(int x)
{
	int m, l = 0, r = tot - 1;

	while (l <= r) {
		m = (l + r) >> 1;
		if (v[m] <= x)
			l = m + 1;
		else
			r = m - 1;
	}
	return r;
}

int main()
{
	int a, b, t, casen;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	scanf("%d", &t);
	for (casen = 1; casen <= t; casen++) {
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", casen, find(b) - find(a - 1));
	}
	return 0;
}