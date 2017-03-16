#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

FILE *wfp;

char input[3000];
int digit[10];
int alpha[26];

int main() {
	int ts, len;

	wfp = fopen("output.txt", "w");

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &ts);

	for (int t = 1; t <= ts; t++) {
		scanf("%s", input);

		for (int i = 0; i < 26; i++)
			alpha[i] = 0;

		for (int i = 0; i < 10; i++)
			digit[i] = 0;

		len = strlen(input);

		for (int i = 0; i < len; i++) {
			alpha[input[i] - 'A']++;
		}

		while (alpha['Z' - 'A'] > 0 && alpha['E' - 'A'] && alpha['R' - 'A'] && alpha['O' - 'A']) {
			digit[0]++;
			alpha['Z' - 'A']--;
			alpha['E' - 'A']--;
			alpha['R' - 'A']--;
			alpha['O' - 'A']--;
		}
		while (alpha['T' - 'A'] > 0 && alpha['W' - 'A'] && alpha['O' - 'A']) {
			digit[2]++;
			alpha['T' - 'A']--;
			alpha['W' - 'A']--;
			alpha['O' - 'A']--;
		}
		while (alpha['F' - 'A'] > 0 && alpha['O' - 'A'] && alpha['U' - 'A'] && alpha['R' - 'A']) {
			digit[4]++;
			alpha['F' - 'A']--;
			alpha['O' - 'A']--;
			alpha['U' - 'A']--;
			alpha['R' - 'A']--;
		}
		while (alpha['T' - 'A'] > 0 && alpha['H' - 'A'] && alpha['R' - 'A'] && alpha['E' - 'A'] && alpha['E' - 'A']) {
			digit[3]++;
			alpha['T' - 'A']--;
			alpha['H' - 'A']--;
			alpha['R' - 'A']--;
			alpha['E' - 'A']--;
			alpha['E' - 'A']--;
		}
		while (alpha['F' - 'A'] > 0 && alpha['I' - 'A'] && alpha['V' - 'A'] && alpha['E' - 'A']) {
			digit[5]++;
			alpha['F' - 'A']--;
			alpha['I' - 'A']--;
			alpha['V' - 'A']--;
			alpha['E' - 'A']--;
		}
		while (alpha['S' - 'A'] > 0 && alpha['I' - 'A'] && alpha['X' - 'A']) {
			digit[6]++;
			alpha['S' - 'A']--;
			alpha['I' - 'A']--;
			alpha['X' - 'A']--;
		}
		while (alpha['S' - 'A'] > 0 && alpha['E' - 'A'] && alpha['V' - 'A'] && alpha['E' - 'A'] && alpha['N' - 'A']) {
			digit[7]++;
			alpha['S' - 'A']--;
			alpha['E' - 'A']--;
			alpha['V' - 'A']--;
			alpha['E' - 'A']--;
			alpha['N' - 'A']--;
		}
		while (alpha['E' - 'A'] > 0 && alpha['I' - 'A'] && alpha['G' - 'A'] && alpha['H' - 'A'] && alpha['T' - 'A']) {
			digit[8]++;
			alpha['E' - 'A']--;
			alpha['I' - 'A']--;
			alpha['G' - 'A']--;
			alpha['H' - 'A']--;
			alpha['T' - 'A']--;
		}
		while (alpha['O' - 'A'] > 0 && alpha['N' - 'A'] && alpha['E' - 'A']) {
			digit[1]++;
			alpha['O' - 'A']--;
			alpha['N' - 'A']--;
			alpha['E' - 'A']--;
		}
		while (alpha['N' - 'A'] > 0 && alpha['I' - 'A'] && alpha['N' - 'A'] && alpha['E' - 'A']) {
			digit[9]++;
			alpha['N' - 'A']--;
			alpha['I' - 'A']--;
			alpha['N' - 'A']--;
			alpha['E' - 'A']--;
		}

		fprintf(wfp, "Case #%d: ", t);
		for (int i = 0; i <= 9; i++) {
			while (digit[i] > 0) {
				fprintf(wfp, "%d", i);
				digit[i]--;
			}
		}
		fprintf(wfp, "\n");
	}

	fclose(wfp);

	return 0;
}
