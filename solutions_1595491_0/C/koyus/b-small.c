#include <stdio.h>

int main() {
	int i, j, T, N, S, p;
	int count;
	int scount;
	int score;
	int tmp;
	FILE *in, *out;

	in = fopen("B-small-attempt2.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);
	for(i = 0; i < T; i++) {
		fscanf(in, "%d", &N);
		fscanf(in, "%d", &S);
		fscanf(in, "%d", &p);
		count = scount = 0;
		for(j = 0; j < N; j++) {
			fscanf(in, "%d", &score);
			if (score < p) continue;
			tmp = p - (int) ((score - p) / 2);
			if (tmp < 2) count++;
			else if (tmp == 2) {
				if (scount < S) {
					scount++;
					count++;
				}
			}
		}
		fprintf(out, "Case #%d: %d\n", i+1, count);
	}
	fclose(in);
	fclose(out);
}
