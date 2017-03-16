#include <stdio.h>
#include <math.h>

int main() {
	int R, C, W;
	int TOTAL, iter;
	FILE *in, *out;
	float tmp;
	int r;

	in = fopen("example.in", "r");
	out = fopen("output.out", "w");

	fscanf(in, "%d\n", &TOTAL);
	for(iter = 0; iter < TOTAL; iter++) {
		fscanf(in, "%d %d %d", &R, &C, &W);
		tmp = ceil((float)C / (float)W);
		printf("%f\n", tmp);
		r = R * (int)tmp + W - 1;
		fprintf(stdout, "Case #%d: %d\n", iter + 1, r);
		fprintf(out, "Case #%d: %d\n", iter + 1, r);
	}





	fclose(in);
	fclose(out);
	return 1;
}