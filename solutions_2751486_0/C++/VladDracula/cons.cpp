#include <stdio.h>
#include <string.h>

#define INFILE		"cons.in"
#define OUTFILE		"cons.out"

char str[1<<20];
bool vowel[26];
int n;

void solve(FILE *fin, FILE *fout) {
	int tests;

	memset(vowel, 0, sizeof(vowel));
	vowel['a'-'a'] = 1;
	vowel['e'-'a'] = 1;
	vowel['i'-'a'] = 1;
	vowel['o'-'a'] = 1;
	vowel['u'-'a'] = 1;

	fscanf(fin, "%d", &tests);
	for (int t=0; t<tests; t++) {
		fscanf(fin, "%s %d\n", str, &n);

		int len = strlen(str);
		int firstn = -1;
		int numCons = 0;
		long long ans = 0;

		for (int i=0; i<len; i++) {
			if (!vowel[str[i]-'a'])
				numCons++;
			else
				numCons = 0;
			if (numCons >= n)
				firstn = i - n + 1;

			if (firstn >= 0) {
				ans += (long long)(firstn + 1);
			}
		}

		fprintf(fout, "Case #%d: %I64d\n", t+1, ans);
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
