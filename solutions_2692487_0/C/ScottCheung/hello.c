#include <stdio.h>
#include <stdlib.h>

int v[105];

int cmp(const void *a, const void *b)
{return *(int *)a - *(int *)b;}

int main()
{
	int a, i, n, t, ans, tmp, casen;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (casen = 1; casen <= t; casen++) {
		scanf("%d%d", &a, &n);
		for (i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		if (a == 1) {
			printf("Case #%d: %d\n", casen, n);
			continue;
		}
		qsort(v + 1, n, sizeof(v[1]), cmp);
		ans = n;
		tmp = 0;
		for (i = 1; i <= n; i++) {
			if (tmp + n - i + 1 < ans)
				ans = tmp + n - i + 1;
			while (a <= v[i]) {
				a = (a << 1) - 1;
				tmp++;
			}
			a += v[i];
		}
		if (tmp < ans)
			ans = tmp;
		printf("Case #%d: %d\n", casen, ans);
	}
	return 0;
}