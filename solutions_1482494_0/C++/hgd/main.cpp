#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>

int a[1000], b[1000], m[1000];
int n, nstars, l;

bool work() {
	bool change = false;
	for (int i = 0; i < n; ++i) {
		if (m[i] && b[i] <= nstars) {
			++l;
			nstars += m[i];
			m[i] = 0;
			change = true;
		}
	}
	if (change) return true;
	int k = -1, max = -1;
	for (int i = 0; i < n; ++i) {
		if (m[i] == 2 && a[i] <= nstars && b[i] > max) {
			k = i;
			max = b[i];
		}
	}
	if (k < 0) return false;
	++l;
	++nstars;
	--m[k];
	return true;
}

int main() {
	FILE *fin = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int t;
	fscanf(fin, "%d", &t);
	for (int i = 1; i <= t; ++i) {
		fscanf(fin, "%d", &n);
		nstars = 0;
		l = 0;
		for (int j = 0; j < n; ++j) {
			fscanf(fin, "%d%d", &a[j], &b[j]);
			m[j] = 2;
		}
		while (work());
		fprintf(fout, "Case #%d: ", i);
		if (nstars < n + n) fprintf(fout, "Too Bad\n");
		else fprintf(fout, "%d\n", l);
	}
	fclose(fout);
	fclose(fin);
	return 0;
}
