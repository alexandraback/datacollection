#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 3

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

int main() {
	FILE *out = fopen("ouput.out", "w");
	in = fopen("D-small-attempt1.in", "r");
	int N = readi('\n');
	int x, r, c;
	bool valid = false; // Can Richard choose an X-omino guaranteeing him a victory?

	for (int i = 0; i < N; i++) {
		x = readi(' ');
		r = readi(' ');
		c = readi('\n');
		valid = false;

		if (x == 1);
		else if ((r*c) % x != 0) valid = true;
		else if (x > r && x > c) valid = true;
		else {
			if (x % 2 == 1) {
				if (x / 2 + 1 > r) valid = true;
				else if (x / 2 + 1 > c) valid = true;
			}
			else {
				if (x / 2 > r) valid = true;
				else if (x / 2 > c) valid = true;
			}

			if (!valid) {
				if (x > 6) valid = true;
				else if (x == 4 && (r == 2 || c == 2)) valid = true;
				else if (x == 6 && (r == 3 || c == 3)) valid = true;
			}
		}

		if (valid) fprintf(out, "Case #%d: RICHARD", i + 1);
		else fprintf(out, "Case #%d: GABRIEL", i + 1);
		if (i < N - 1) fprintf(out, "\n");
	}

	fclose(out);
	fclose(in);
	return 0;
}