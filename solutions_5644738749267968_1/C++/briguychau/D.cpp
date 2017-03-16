#include <stdio.h>

double a[1001];
double b[1001];
double c[1001];
double d[1001];
int n;

void percolatedown(double* a, int size, int current) {
	int temp1 = 2 * current + 1;
	int temp2 = temp1 + 1;
	int max = current;
	if (temp1 < size && a[temp1] > a[current]) max = temp1;
	if (temp2 < size && a[temp2] > a[max]) max = temp2;
	if (max != current) {
		double temp = a[current];
		a[current] = a[max];
		a[max] = temp;
		percolatedown(a, size, max);
	}
}

void heapify(double* a, int size) {
	for (int k = size - 1; k >= 0; k--) {
		percolatedown(a, size, k);
	}
}

void sort(double* a, int size) {
	heapify(a, size);
	int j = size;
	for (int k = size - 1; k >= 0; k--) {
		double temp = a[0];
		a[0] = a[k];
		a[k] = temp;
		j--;
		percolatedown(a, j, 0);
	}
}

void sortAB() {
	sort(a, n);
	sort(b, n);
}

void solve(int asdfasdf) {
	printf("Case #%d: ", asdfasdf);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &b[i]);
	}
	sortAB();
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
		d[i] = b[i];
	}
	// arr c, d: deceptive war
	int strc = 0, strd = 0, endc = n - 1, endd = n - 1;
	int score = 0;
	for (int i = 0; i < n; i++) {
		if (c[strc] > d[strd]) {
			strc++;
			strd++;
			score++;
		} else {
			// c[strc] < d[strd]
			while (c[endc] > d[endd]) {
				i++;
				endc--;
				endd--;
				score++;
			}
			strc++;
			endd--;
		}
	}

	printf("%d ", score);

	// arr a, b: regular war
	int strb = 0, enda = n - 1, endb = n - 1;
	score = 0;
	for (int i = 0; i < n; i++) {
		if (b[endb] > a[enda--]) {
			endb--;
		} else {
			strb++;
			score++;
		}
	}
	printf("%d\n", score);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}