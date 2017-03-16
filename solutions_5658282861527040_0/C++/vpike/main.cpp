#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *f = fopen((argc > 1 ? argv[1] : "in.txt"), "r");
	FILE *g = fopen("out.txt", "w");
	int t;
	char lines[100][110];
	char a[100];
	int a_size;
	char a_counts[100][100];

	fscanf(f, "%d\n", &t);
	for (int test = 0; test < t; test++) {
		int cnt = 0;
		int A, B, K;
		int k;
		fscanf(f, "%d %d %d\n", &A, &B, &K);
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++) {
				k = a & b;
				if (k < K)
					cnt++;
			}
		fprintf(g, "Case #%d: %d\n", test + 1, cnt);
	}
	fclose(f);
	fclose(g);
	return 0;
}

