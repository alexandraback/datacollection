#include <stdio.h>

int n, s, p;
int score[1024];
int res;

int main() {
	FILE *fi = fopen("b.in", "r");
	FILE *fo = fopen("b.out", "w");

	int tests;
	fscanf(fi, "%d", &tests);
	for (int i=0; i<tests; i++) {
		res=0;
		fscanf(fi, "%d%d%d", &n, &s, &p);
		for (int j=0; j<n; j++) {
			fscanf(fi, "%d", score+j);
			int left = score[j]-p;
			if (left>=0) {
				int smaller = left/2;
				if (p-smaller<2)
					res++;
				else if (s && p-smaller==2) {
					res++;
					s--;
				}
			}
		}
		fprintf(fo, "Case #%d: %d\n", i+1, res);
	}

	fclose(fi);
	fclose(fo);

	return 0;
}
