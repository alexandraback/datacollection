#include <stdio.h>
#include <malloc.h>
#include <math.h>


int main(int argc, char **argv)
{
	FILE *f;
	int A, B, cnt, numdigits, cand, topdigit;
	int cs, offset = 0;
	int i, j, k;
	int list[8], found;

	f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 0;
	}

	//fscanf(f, "%d %d", &i, &offset);
	fscanf(f, "%d", &i);
	fprintf(stderr, "%d cases, offset %d\n", i, offset);
	cs = 0;
	while (fscanf(f, "%d %d", &A, &B) != EOF) {
		numdigits = log10(A);
		for (topdigit = 1, i = 0; i < numdigits; i++, topdigit *= 10);
		fprintf(stderr, "Case %d, A=%d, B=%d, digits=%d topdigit =%d\n", i+1, A, B, numdigits, topdigit);
		cnt = 0;
		for (i = A; i <= B; i++) {
			memset(list, 0, 8 * sizeof(int));
			cand = i;
			//fprintf(stderr, "%d: ", cand);
			for (j = 0; j < numdigits; j++) {
				cand = (cand / 10) + (cand % 10) * topdigit;
				//fprintf(stderr, "%d, ", cand);
				if (cand <= i || cand > B)	continue;
				found = 0;
				for (k = 0; k < j; k++)
					if (list[k] == cand) {
						//printf("found %d %d %d\n", i, list[k], cand);
						found = 1;
						break;
					}
				if (found)	continue;
				cnt++;
				list[j] = cand;
				//fprintf(stderr, "%d, %d\n", i, cand);
				//fprintf(stderr, "%d, ", cand);
				//fprintf(stderr, "<-- ", cand);
			}
				//fprintf(stderr, "\n");
		}
		printf("Case #%d: %d\n", cs + offset + 1, cnt);
		cs++;
	}

	return 0;
}
