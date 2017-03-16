#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> count(double a[], double b[], int n) {
	sort(a, a + n);
	sort(b, b + n);

	int cw = 0, dw = 0, i, j, k;

	for (i = j = 0, k = n - 1; i < n; i++) {
		if (k >= 0 && a[n - i - 1] > b[k]) {
			cw++;
		} else {
			k--;
		}

		if (a[i] > b[j]) {
			dw++;
			j++;
		}
	}

	return make_pair(dw, cw);
}

int main()
{
	int t;
	scanf("%d", &t);

	int i;
	for (i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);

		double *a = (double *) malloc(n * sizeof(double));
		double *b = (double *) malloc(n * sizeof(double));

		int j;
		for (j = 0; j < n; j++) {
			scanf("%lf", &a[j]);
		}

		for (j = 0; j < n; j++) {
			scanf("%lf", &b[j]);
		}

		pair<int, int> c = count(a, b, n);

		printf("Case #%d: %d %d\n", i, c.first, c.second);
	}

	return 0;
}
