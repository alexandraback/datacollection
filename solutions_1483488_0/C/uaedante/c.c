#include <stdio.h>
#define MAX(i, j) (((i)>(j))?(i):(j))

inline int callen(int i, int *mask)
{
	int j = 0;
	int k = 1;
	while (i) {
		j++;
		i /= 10;
		k *= 10;
	}
	*mask = k;
	return j;
}

inline int next(int i, int len, int mask)
{
	int j = i * 10;
	return (j + j / mask) % mask;
}

int main()
{
	int t, cc, i, j, k, l, r, sum, len, mask, a[10];
	scanf("%d", &t);
	for (cc = 1; cc <= t; cc++) {
		scanf("%d %d", &l, &r);
		sum = 0;
		for (i = l; i <= r; i++) {
			len = callen(i, &mask);
			j = i;
			int it = 0;
			for (k = 1; k < len; k++) {
				j = next(j, len, mask);
				if (i < j && j <= r) {
					int s;
					for (s = 1; s <= it; s++)
						if (a[s] == j) break;
					if (s == it + 1) a[++it] = j;
				}
			}
			sum += it;
			//printf("%d %d %d %d\n", i, sum, len, j);
		}
		printf("Case #%d: %d\n", cc, sum);
	}
}
