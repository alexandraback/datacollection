#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2)
{
	double d = *(double*)e1 - *(double*)e2;
	if (d >= 0) return 1;
	return -1;
}

int war(double n[], double k[], int N)
{
	int n1, n2, k1, k2, p;
	p = n1 = k1 = 0;
	n2 = k2 = N - 1;
	while (N--)
	{
		if (n[n2] > k[k2])
		{
			p++;
			k1++;
		}
		else
			k2--;
		n2--;
	}
	return p;
}

int main(int argc, char **argv)
{
	int T, x, N, i;
	double n[50], k[50];
	scanf("%d ", &T);
	for (x = 1; x <= T; x++)
	{
		scanf("%d ", &N);
		for (i = 0; i < N; i++) scanf("%lf ", n + i);
		qsort(n, N, sizeof(double), &cmp);
		for (i = 0; i < N; i++) scanf("%lf ", k + i);
		qsort(k, N, sizeof(double), &cmp);
		printf("Case #%d: %d %d\n", x, N - war(k, n, N), war(n, k, N));
	}
	return 0;
}