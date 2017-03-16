#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *f;
	int numcases, cs;
	int i;
	int N, s[256], X, flag, Np;
	float yi[256], sum;

	f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 1;
	}
	fscanf(f, "%d\n", &numcases);
	fprintf(stderr, "%d cases\n", numcases);

	for (cs = 1; cs <= numcases; cs++) {
		fscanf(f, "%d", &N);
		X = 0;
		for (i = 0; i < N; i++) {
			fscanf(f, "%d", &s[i]);
			X += s[i];
		}

		sum = 0.0f;
		Np = 0;
		for (i = 0; i < N; i++) {
			yi[i] = 100.0f * ((float) 2 * X - N * s[i]) / ((float) X * N);
			if (yi[i] < 0.0f) {
				sum += yi[i];
				yi[i] = 0.0f;
			} else
				Np++;
		}
		sum /= (float) Np;
		if (sum < 0.0f) {
			for (i = 0; i < N; i++)
				if (yi[i] > 0.0f)
					yi[i] += sum;
		}
		printf("Case #%d:", cs);
		for (i = 0; i < N; i++)
			printf(" %.6f", yi[i]);
		printf("\n");
	}

	return 0;
}
