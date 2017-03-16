#include <stdio.h>
#include <string.h>

#define MAX 20
#define TOTAL 2000000
#define BIT 1048575

int
test_bit (int num, int index)
{
	if (num & (1 << index)) {
		return 1;
	}
	return 0;
}

int
main (void)
{
	int T, N, max;
	int i, j, k, l, num[MAX];
	char hash[TOTAL];
	int sum, tmp;

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf ("%d", &N);
		memset (hash, 0, sizeof (hash));

		max = 1 << N;
		for (j = 0; j < N; ++j) {
			scanf ("%d", num + j);
		}
		
		printf ("Case #%d:\n", i);
		for (j = 1; j < max; ++j) {
			sum = 0;
			for (k = 0; k < N; ++k) {
				sum += num[k] * test_bit (j, k); 
			}
			if (hash[sum]) {
				for (k = 0; k < N; ++k) {
					if (test_bit (j, k)) {
						printf ("%d ", num[k]);
					}
				}
				printf ("\n");
				for (k = 1; k < j; ++k) {
					tmp = 0;
					for (l = 0; l < N; ++l) {
						tmp += num[l] * test_bit (k, l);
					}
					if (tmp == sum) {
						for (l = 0; l < N; ++l) {
							if (test_bit (k, l)) {
								printf ("%d ", num[l]);
							}
						}
						printf ("\n");
					}
				}
				break;
			} else {
				hash[sum] = 1;
			}
		}
	}
	return 0;
}
