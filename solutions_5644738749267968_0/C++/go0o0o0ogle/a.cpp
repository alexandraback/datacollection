#include <stdio.h>
#include <stdlib.h>

double a[1000];
double b[1000];
int n;

int score1()
{
	int i, j;
	int score = 0;
	int posa = 0;
	for (i = 0; i < n; i++) {
		double vb = b[i];
		while (posa < n) {
			double va = a[posa++];
			if (va > vb) {
				score++;
				break;
			}
		}
		if (posa >= n) {
			break;
		}
	}
	return score;
}

int score2()
{
	int i, j;
	int lost = 0;
	int posb = 0;
	for (i = 0; i < n; i++) {
		double va = a[i];
		while (posb < n) {
			double vb = b[posb++];
			if (vb > va) {
				lost++;
				break;
			}
		}
		if (posb >= n) {
			break;
		}
	}
	return n - lost;
}

int cmp(const void *ppa, const void *ppb)
{
	double *pa = (double *)ppa;
	double *pb = (double *)ppb;
	if (*pa - *pb > 0) {
		return 1;
	}
	return -1;
}

int main()
{
	int k, t;
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		scanf("%d", &n);
		int i;
		for (i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%lf", &b[i]);
		}
		qsort(a, n, sizeof (double), cmp);
		qsort(b, n, sizeof (double), cmp);
		printf("Case #%d: %d %d\n", k + 1, score1(), score2());
	}
	return 0;
}