#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 5

#include <stdio.h>
#include <stdlib.h>

FILE *in;

int readi(char delim) {
	char a, buffer[BUFFER_SIZE];
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

char * gen_str(long int l) {
	char a, buffer[13];
	long int x = 0, k = 1;
	int i = 0;
	while ((a = fgetc(in)) != '\n') {
		buffer[i] = a;
		i++;
	}
	for (int j = i - 1; j > -1; j--, k *= 10) {
		x += (buffer[j] - '0') * k;
	}
	char * r = (char *)malloc((l*x + 1)*sizeof(char));

	for (long int i = 0; i < l; i++) {
		a = fgetc(in) - 'g';
		for (long int j = 0; j < x; j++) {
			r[i + j*l] = a;
		}
	}
	r[l*x] = 0;

	return r;
}

int main() {
	FILE *out = fopen("ouput.out", "w");
	in = fopen("C-small-attempt0.in", "r");
	int N = readi('\n');
	int l;
	char bla[8][4] = { { -4, -3, 2, 1 }, { -3, 4, 1, -2 }, { -2, 1, -4, 3 }, { -1, -2, -3, -4 }, { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
	char a, b, c;
	bool valid;

	char **m = (char**)malloc(9 * sizeof(char*));
	m = &m[4];
	for (int i = -4; i < 5; i++) {
		if (i < 0) {
			m[i] = bla[i + 4];
		}
		else if (i > 0) {
			m[i] = bla[i + 3];
		}
	}

	for (int i = 0; i < N; i++) {
		l = readi(' ');
		char *s = gen_str((long int)l);
		valid = false;
		a = 1;

		for (int j = 0; s[j]; j++) {
			a = m[a][s[j] - 1];
			if (a == 2) {
				b = 1;

				for (int k = j + 1; s[k]; k++) {
					b = m[b][s[k] - 1];
					if (b == 3) {
						c = 1;

						for (int p = k + 1; s[p]; p++) {
							c = m[c][s[p] - 1];
						}
						if (c == 4) {
							valid = true;
							break;
						}
					}
				}
				if (valid) break;
			}
		}

		if (valid) fprintf(out, "Case #%d: YES", i + 1);
		else fprintf(out, "Case #%d: NO", i + 1);
		if (i < N - 1) fprintf(out, "\n");

		fgetc(in);
		free(s);
	}

	free(&m[-4]);
	fclose(out);
	fclose(in);
	return 0;
}

//I am using long int to store the number of repetitions "X". I would like to emphasize that it is large enough on my system.