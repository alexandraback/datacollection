#include <stdio.h>
#include <math.h>

int main() {
	int K, L, S;
	int TOTAL, iter, i, j;
	FILE *in, *out;
	char keyboard[100];
	char target[100];
	double distribution[26];
	double r = 1.0, e, m;
	double dk;
	char possible;
	int dup, uniq;

	in = fopen("example.in", "r");
	out = fopen("output.out", "w");

	fscanf(in, "%d\n", &TOTAL);
	for(iter = 0; iter < TOTAL; iter++) {
		fscanf(in, "%d %d %d\n", &K, &L, &S);
		dk = 1.0 / (double)K;
		fgets(keyboard, 100, in);
		fgets(target, 100, in);
		for(i = 0; i < 26; i++) {
			distribution[i] = 0.0;
		}
		for(i = 0; i < K; i++) {
			distribution[keyboard[i] - 'A'] += dk;
		}
		// now find the max and exp of typing
		possible = 1;
		for(i = 0; i < L; i++) {
			if(distribution[target[i] - 'A'] < 0.000000000000000001) {
				possible = 0;
				break;
			}
		}
		if(!possible) {
			fprintf(stdout, "Case #%d: %g\n", iter + 1, 0.0);
			fprintf(out, "Case #%d: %g\n", iter + 1, 0.0);
			continue;
		}

		if(L > 1) {
			for(i = 1; i < L; i++) {
				possible = 1;
				for(j = 0; i + j < L; j++) {
					if(target[j] != target[i + j]) {
						possible = 0;
						break;
					}
				}
				if(possible) {
					break;
				}
			}
		}
		if((!possible) || (L == 1)) {
			m = floor((double)S / (double)L);
		}
		else {
			m = floor((double)(S - j) / (double)(L - j));
		}

		e = 1.0;
		for(i = 0; i < L; i++) {
			e *= distribution[target[i] - 'A'];
		}

		r = (1.0 - e) * m;



		

		fprintf(stdout, "Case #%d: %g\n", iter + 1, r);
		fprintf(out, "Case #%d: %g\n", iter + 1, r);
	}





	fclose(in);
	fclose(out);
	return 1;
}