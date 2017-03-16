#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long palindrome(long num) {
	long digits[20];
	memset(digits, -1, 20);

	long digit_num = 0;

	long tmp = num;

	while (tmp != 0) {
		digits[digit_num] = tmp % 10;
		++digit_num;
		tmp /= 10;
	}

	long i;
	for (i = 0; i < digit_num/2; ++i) {
		if (digits[i] != digits[digit_num - i - 1])
			break;
	}

	if (i != digit_num/2) {
		return 0;
	}
	else {
		return 1;
	}
}

int main(int argc, char *argv[]) {

	FILE *f = fopen("3.in", "r");
	FILE *f2 = fopen("computed.in", "r");

	long already_computed[1000];
	memset(already_computed, 0, 1000*sizeof(long));
	int computed_index = 0;

	while (42) {
		long next_val = -1;

		fscanf(f2, "%li", &next_val);

		if (next_val == EOF)
			break;

		already_computed[computed_index] = next_val;
		++computed_index;
	}

	long i, j, k, l, m, n, o;

	long cases;
	fscanf(f, "%li", &cases);

	for (i = 1; i <= cases; ++i) {
		long A;
		long B;

		fscanf(f, "%li %li", &A, &B); 

		int p_count = 0;

		for (j = 0; j < computed_index; ++j) {
			if (already_computed[j] < A)
				continue;

			if (already_computed[j] > B)
				break;

			++p_count;
		}


		/*

		long p_count = 0;

		int test1 = (long) sqrt(A);

		if (test1*test1 == A) {
			k = test1;
		}
		else {
			k = test1 + 1;
		}

		int test2 = (long) sqrt(B);

		if (test2*test2 == B) {
			l = test2;
		}
		else {
			l = test2 - 1;
		}

		for (; k <= l; ++k) {
			j = k*k;

			long pal = palindrome(j);
			
			if (!pal)
				continue;

			long pal2 = palindrome(k);

			if (!pal2)
				continue;

			++p_count;
		}

		*/

		printf("Case #%i: %i\n", i, p_count);
	}


	fclose(f2);
	fclose(f);

	return 0;
}
