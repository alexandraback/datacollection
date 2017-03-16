#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {

	FILE *f = fopen("2.in", "r");

	int i, j, k, l, m, n, o;

	int cases;
	fscanf(f, "%i", &cases);

	for (i = 1; i <= cases; ++i) {
		int n, m;

		fscanf(f, "%i %i", &n, &m);

		int lawn[n][m];
		for (j = 0; j < n; ++j) {
			for (k = 0; k < m; ++k) {
				fscanf(f, "%i", &lawn[j][k]);
			}
		}

		for (j = 0; j < n; ++j) {
			for (k = 0; k < m; ++k) {
				int failed = 0;

				for (l = 0; l < n; ++l) {
					if (lawn[l][k] > lawn[j][k]) {
						break;
					}
				}

				if (l != n)
					++failed;

				for (l = 0; l < m; ++l) {
					if (lawn[j][l] > lawn[j][k]) {
						break;
					}
				}

				if (l != m)
					++failed;

				if (failed >= 2)
					goto fail;
			}
		}
		
		goto success;

		fail:
			printf("Case #%i: NO\n", i);
		
		goto end;

		success:
			printf("Case #%i: YES\n", i);

		end:
			continue;
	}


	fclose(f);

	return 0;
}
