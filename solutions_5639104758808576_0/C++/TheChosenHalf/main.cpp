#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *in;

int readi(char delim) {
	char a, buffer[4];
	int r = 0, i = 0, k = 1;
	while ((a = fgetc(in)) != delim) {
		buffer[i] = a;
		i++;
	}
	for (int j = i - 1; j > -1; j--, k *= 10) {
		r += (buffer[j] - '0') * k;
	}
	return r;
}

int main() {
	FILE *out = fopen("ouput.out", "w");
	in = fopen("A-small-attempt0.in", "r");
	int N = readi('\n');
	int smax = 0, n = 0, t, friends;

	for (int j = 0; j < N; j++) {
		smax = readi(' ') + 1;
		n = fgetc(in) - '0';
		friends = 0;
		for (int k = 1; k < smax; k++) {
			t = fgetc(in) - '0';
			if (n < k) {
				friends += k - n;
				n = k + t;
			}
			else {
				n += t;
			}
		}
		if (j == N - 1) {
			fprintf(out, "Case #%d: %d", j + 1, friends);
		}
		else {
			fprintf(out, "Case #%d: %d\n", j + 1, friends);
		}
		fgetc(in);
	}

	fclose(out);
	fclose(in);
	return 0;
}