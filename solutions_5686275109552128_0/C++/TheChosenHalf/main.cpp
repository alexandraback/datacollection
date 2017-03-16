#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

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
	in = fopen("B-small-attempt0.in", "r");
	int N = readi('\n');
	int D, time, *d, max, t;

	for (int j = 0; j < N; j++) {
		D = readi('\n');
		d = (int*)malloc(D*sizeof(int));
		time = 1000000000;
		max = 0;
		for (int k = 0; k < D; k++) {
			if (k == D - 1) d[k] = readi('\n');
			else d[k] = readi(' ');
			if (d[k] > max) max = d[k];
		}

		max++;
		for (int k = 1; k < max; k++) {
			t = 0;
			for (int m = 0; m < D; m++) {
				t += (d[m] % k) ? (d[m] / k) : (d[m] / k - 1);
			}
			if (t + k < time) time = t + k;
		}

		if (j == N - 1) {
			fprintf(out, "Case #%d: %d", j + 1, time);
		}
		else {
			fprintf(out, "Case #%d: %d\n", j + 1, time);
		}
		free((void *)d);
	}

	fclose(out);
	fclose(in);
	return 0;
}

//I also added a new line at the end of the input file (at the last line) to avoid reading input beyond the end of the file.