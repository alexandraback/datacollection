#include <cstdio>

int a, b;
int curr[10];
int cnum;

int main() {
	FILE *fi = fopen("c.in", "r");
	FILE *fo = fopen("c.out", "w");

	int tests;
	fscanf(fi, "%d", &tests);
	for (int i=0; i<tests; i++) {
		fscanf(fi, "%d%d", &a, &b);
		int res = 0;
		int p = 1;
		int t = a;
		while (t) { t/=10; p*=10; }
		p/=10;
		for (int j=a; j<b; j++) {
			int s1 = p;
			int s2 = 10;
			cnum=0;
			while (s1 > 1) {
				int t = (j%s1)*s2+j/s1;
				if (t>j && t<=b) {
					curr[cnum++]=t;
				}
				s1 /= 10;
				s2 *= 10;
			}

			for (int k=0; k<cnum; k++) {
				int yes = true;
				for (int l=k+1; l<cnum; l++)
					if (curr[k]==curr[l]) {
						yes = false;
						break;
					}
				if (yes)
					res++;
			}
		}
		fprintf(fo, "Case #%d: %d\n", i+1, res);
	}

	fclose(fi);
	fclose(fo);

	return 0;
}
