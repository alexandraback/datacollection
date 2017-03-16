#include<stdio.h>

int rotateNumber(int a, int digit) {
	return (a/10) + (a % 10) * digit;
}

int digitOf(int a) {
	int b = 1;
	while(a!=0) {
		a /= 10;
		b *= 10;
	}
	return b/10;
}

int main() {
	int i, j, T, A, B;
	int tmp;
	int digit;
	int count, tmpcount;
	FILE *in, *out;

	in = fopen("C-small-attempt0.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(in, "%d %d", &A, &B);
		count = 0;
		for(j = A; j <= B; j++) {
			tmp = j;
			digit = digitOf(j);
			tmpcount = 1;
			while(1) {
				tmp = rotateNumber(tmp, digit);
				if (tmp == j) break;
				if (tmp>=A && tmp <= B) {
					if (tmp < j) {
						tmpcount = 0;
						break;
					}else{
						tmpcount++;
					}
				}
			}
			count += tmpcount*(tmpcount-1)/2;
		}
		fprintf(out, "Case #%d: %d\n", i+1, count);
	}
	fclose(out);
}
