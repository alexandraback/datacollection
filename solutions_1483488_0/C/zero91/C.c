#include <stdio.h>

int
get_cycle_num (int num, int digit, int bits)
{
	int i;
	int factor_left, factor_right;

	factor_right = factor_left = 1;
	for (i = 1; i <= digit - bits; ++i)
		factor_left *= 10;
	for (i = 1; i <= bits; ++i)
		factor_right *= 10;
	return (num % factor_right) * factor_left + num / factor_right;
}

int
main (void)
{
	int T, A, B;
	int i, j, k;
	int result, digit, num;

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf ("%d%d", &A, &B);

		digit = 0;
		num = A;
		while (num != 0) {
			++digit; 
			num /= 10;
		}
		result = 0;
		for (j = A; j <= B; ++j) {
			for (k = 1; k < digit; ++k) {
				num = get_cycle_num (j, digit, k);
				if (num > j && num <= B) {
					++result;
				} else if (num == j) {
					break;
				}
			}
		}
		printf ("Case #%d: %d\n", i, result);
	}
	return 0;
}
