/*New Lottery Game*/

#include<stdio.h>

int main()
{
	int A, B, count, i, j, K, t, T;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &A, &B, &K);
		count = 0;
		for (i = 0; i < A; i++)
			for (j = 0; j < B; j++)
				if ((i & j) < K)
					count++;
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}