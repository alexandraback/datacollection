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

long long int readlli(char delim) {
	char a, buffer[13];
	long long int r = 0LL, k = 1LL;
	int i = 0;
	while ((a = fgetc(in)) != delim) {
		buffer[i] = a;
		i++;
	}
	for (int j = i - 1; j > -1; j--, k *= 10LL) {
		r += (buffer[j] - '0') * k;
	}
	return r;
}

int main() {
	FILE *out = fopen("ouput.out", "w");
	in = fopen("C-large.in", "r");
	int N = readi('\n');
	long long int x, l, n, tmp;
	char bla[8][4] = { { -4, -3, 2, 1 }, { -3, 4, 1, -2 }, { -2, 1, -4, 3 }, { -1, -2, -3, -4 }, { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
	char a, b, c, t;
	bool valid, flag;

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
		l = (long long int)readi(' ');
		x = readlli('\n');
		n = l*x;
		valid = false;
		flag = false;
		a = 1;
		char * s = (char *)malloc(l*sizeof(char));

		for (int i = 0; i < l; i++) {
			s[i] = fgetc(in) - 'h';
		}
		fgetc(in);

		t = s[0] + 1;
		for (long long int j = 0; j < n; j++) {
			a = m[a][s[j%l]];
			if (a == 2) {
				b = 1;
				t = s[(j + 1)%l] + 1;

				for (long long int k = j + 1; k < n; k++) {
					b = m[b][s[k%l]];
					if (b == 3) {
						flag = true;
						tmp = k + 1;
						break;
					}
					else if ((k - j - 1)%l == 0) {
						if (b == t && k - j - 1 != 0) {
							break;
						}
					}
				}
				break;
			}
			else if (j % l == 0) {
				if (a == t && j != 0) {
					break;
				}
			}
		}

		if (flag) {
			c = 1;
			while (tmp%l != 0) {
				c = m[c][s[tmp%l]];
				tmp++;
			}
			t = 1;
			for (long long int j = 0; j < l; j++) {
				t = m[t][s[j]];
			}
			tmp = (x - tmp / l) % 4;

			if (t < 0) {
				t = -t;
				for (long long int j = 0; j < tmp; j++) {
					c = -m[c][t - 1];
				}
			}
			else {
				for (long long int j = 0; j < tmp; j++) {
					c = m[c][t - 1];
				}
			}
			
			if (c == 4) {
				valid = true;
			}
		}

		if (valid) fprintf(out, "Case #%d: YES", i + 1);
		else fprintf(out, "Case #%d: NO", i + 1);
		if (i < N - 1) fprintf(out, "\n");

		free(s);
	}

	free(&m[-4]);
	fclose(out);
	fclose(in);
	return 0;
}