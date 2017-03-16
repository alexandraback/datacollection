#include <stdio.h>
#include <stdlib.h>

int num_digits(int n);

int count_unique(int * a, int num_elm);

int main() {
	int i, T;

	// cache powers of 10
	int p[10];
	p[0] = 1;
	for(i = 1; i < 10; i++)
		p[i] = 10 * p[i-1];

	scanf("%d\n", &T);
	for(i = 0; i < T; i++) {
		int A, B, k, result;
		int rots[10];

		scanf("%d %d\n", &A, &B);

		k = num_digits(A);
		result = 0;
		
		int n, t;
		for(n = A; n <= B; n++) {
			// collect all rotations m of n that is greater than n, but <= B
			int j = 0;
			for(t = 1; t < k; t++) {
				int m = (n % p[t]) * p[k-t] + (n / p[t]);
				if (n < m && m <= B)
					rots[j++] = m;
			}
			// select unique m in rots
			result += count_unique(rots, j);
		}

		printf("Case #%d: %d\n", i+1, result);
	}
}

int num_digits(int n) {
	if (n == 0)
		return 1;
	
	int r = 0;
	while (n > 0) {
		r++;
		n /= 10;
	}
	return r;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int count_unique(int * a, int num_elm) {
	if (num_elm == 0)
		return 0;

	// sort the array a
	qsort(a, num_elm, sizeof(int), compare);
	
	// count and collapse identical adjacent values
	int x = a[0];
	int result = 1;
	int i;
	for(i = 1; i < num_elm; i++) {
		if (a[i] != x) {
			result++;
			x = a[i];
		}
	}

	return result;
}
