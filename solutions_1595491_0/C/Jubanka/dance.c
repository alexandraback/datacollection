#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int norm[31], surp[31];

void precalc(void)
{
	int i, j, k, min;
	int *tab;

	for (i = 0; i <= 10; i++)
		for (j = MAX(i - 2, 0); j <= i; j++)
			for (k = MAX(i - 2, 0); k <= i; k++) {
				min = MIN(i, MIN(j, k));
				if (min == i - 2)
					tab = surp;
				else
					tab = norm;
				if (tab[i + j + k] < i)
					tab[i + j + k] = i;
			}
}

int main(int argc, char **argv)
{
	FILE *f;
	int numcases, cs;
	int i;
	int N, S, p, t, resn, ress;

	for (i = 0; i <= 30; i++) {
		norm[i] = surp[i] = -1;
	}
	precalc();
	/*fprintf(stderr, "\nnorm: ");
	for (i = 0; i <= 30; i++)
		fprintf(stderr, "%d:%d, ", i, norm[i]);
	fprintf(stderr, "\nsurp: ");
	for (i = 0; i <= 30; i++)
		fprintf(stderr, "%d:%d, ", i, surp[i]);
	return 0;*/

	f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 1;
	}
	fscanf(f, "%d\n", &numcases);
	fprintf(stderr, "%d cases\n", numcases);

	for (cs = 1; cs <= numcases; cs++) {
		fscanf(f, "%d %d %d", &N, &S, &p);

		resn = ress = 0;
		for (i = 0; i < N; i++) {
			fscanf(f, "%d", &t);
			if (norm[t] >= p) {
				resn++;
				continue;
			}
			if (surp[t] >= p && surp[t] != -1) {
				ress++;
				continue;
			}
		}
		printf("Case #%d: %d\n", cs, resn + MIN(ress, S));
	}

	return 0;
}
