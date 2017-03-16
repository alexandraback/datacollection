#include <stdio.h>
#include <math.h>

void percolatedown(int* a, int size, int current) {
	int temp1 = 2 * current + 1;
	int temp2 = temp1 + 1;
	int max = current;
	if (a[temp1] > a[current] && temp1 < size) max = temp1;
	if (a[temp2] > a[max] && temp2 < size) max = temp2;
	if (max != current) {
		int temp = a[current];
		a[current] = a[max];
		a[max] = temp;
		percolatedown(a, size, max);
	}
}

void heapify(int* a, int size) {
	for (int k = size - 1; k >= 0; k--) {
		percolatedown(a, size, k);
	}
}

void sort(int* a, int size) {
	heapify(a, size);
	int j = size;
	for (int k = size - 1; k >= 0; k--) {
		int temp = a[0];
		a[0] = a[k];
		a[k] = temp;
		j--;
		percolatedown(a, j, 0);		
	}
}

int solve_motes(int A, int* motes, int N) {
	if (A == 1) return N;
	int count = 0;
	int newmote;
	for (int i = 0; i < N; ) {
		if (motes[i] < A) {
			A += motes[i];
			i++;
		} else {
			count++;
			int remaining = N - i - 1;
			if (motes[i] < A * (int)pow(2, remaining) - (2 * remaining) + 1) {
				newmote = A - 1;
				A += newmote;
			} else {
				i++;
			}
		}
	}
	return count;
}

void solve(int count) {
	int A, N, result;
	scanf("%d %d", &A, &N);
	int* motes = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &motes[i]);
	}
	sort(motes, N);
	result = solve_motes(A, motes, N);
	printf("Case #%d: %d\n", count, result);
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		solve(i);
	}
	return 0;
}

