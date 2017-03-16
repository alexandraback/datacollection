#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000000

__int64 v[N + 1];
int tot;

void itoall(__int64 x, char s[])
{
	int i = 0;

	while (x) {
		s[i++] = '0' + (int)(x % 10);
		x /= 10;
	}
	s[i] = '\0';
}


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
	char st[20];
	__int64 i, j;

	for (i = 1; i <= N; i++) {
		itoall(i, st);
		if (fair(st)) {
			itoall(j = i * i, st);
			if (fair(st))
				v[tot++] = j;
		}
	}
}

int find(__int64 x)
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
	int t, casen;
	__int64 a, b;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	scanf("%d", &t);
	for (casen = 1; casen <= t; casen++) {
		scanf("%I64d%I64d", &a, &b);
		printf("Case #%d: %d\n", casen, find(b) - find(a - 1));
	}
	return 0;
}