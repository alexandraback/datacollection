#include <stdio.h>
#include <algorithm>

#define INFILE		"osmos.in"
#define OUTFILE		"osmos.out"

int a, n;
int arr[110];
int sol[1<<20][128];
int maxMote;

int getSol(int currA, int first) {
	if (currA > maxMote || first == n)
		return 0;
	return sol[currA][first];
}

int min(int a, int b) {
	return a < b ? a : b;
}

void solve(FILE *fin, FILE *fout) {
	int tests;
	fscanf(fin, "%d", &tests);
	for (int t=0; t<tests; t++) {
		fscanf(fin, "%d%d", &a, &n);
		for (int i=0; i<n; i++)
			fscanf(fin, "%d", arr+i);
		std::sort(arr, arr+n);

		maxMote = arr[n-1];
		int ans = n;

		for (int first=n-1; first>=0; first--)
			for (int currA=maxMote+1; currA>=a; currA--) {
				if (currA > arr[first])
					sol[currA][first] = getSol(currA+arr[first], first+1);
				else {
					int tmpA = currA;
					int add = 0;
					if (tmpA > 1) {
						while (tmpA <= arr[first]) {
							tmpA = tmpA + tmpA - 1;
							add++;
						}
					} else
						add = 110;
					sol[currA][first] = min(getSol(currA, first+1) + 1, getSol(tmpA + arr[first], first+1) + add);
				}
			}

		if (a > maxMote)
			ans = 0;
		else
			ans = sol[a][0];

		fprintf(fout, "Case #%d: %d\n", t+1, ans);
	}
}

int main() {
	FILE *fin = fopen(INFILE, "r");
	FILE *fout = fopen(OUTFILE, "w");
	if (!fin) {
		printf("Cannot open input file!\n");
		return 0;
	}
	if (!fout) {
		printf("Cannot open output file!\n");
		return 0;
	}

	solve(fin, fout);

	fclose(fin);
	fclose(fout);
	return 0;
}
