#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int palindrome(int num) {
	int digits[20];
	memset(digits, -1, 20);

	int digit_num = 0;

	int tmp = num;

	while (tmp != 0) {
		digits[digit_num] = tmp % 10;
		++digit_num;
		tmp /= 10;
	}

	int i;
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

	int i, j, k, l, m, n, o;

	int cases;
	fscanf(f, "%i", &cases);

	for (i = 1; i <= cases; ++i) {
		int A;
		int B;

		fscanf(f, "%i %i", &A, &B); 

		int p_count = 0;

		for (j = A; j <= B; ++j) {
			int pal = palindrome(j);
			
			if (!pal)
				continue;

			int root = (int) sqrt(j);
			
			if (root*root != j) {
				continue;	
			}

			int pal2 = palindrome(root);

			if (!pal2)
				continue;

			++p_count;
		}

		printf("Case #%i: %i\n", i, p_count);
	}


	fclose(f);

	return 0;
}
