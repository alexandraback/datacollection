#include <cstdio>
#include <cstring>

int main() {
	char table[128];
	memset(table, -1, sizeof(table));

	FILE* fIn = fopen("in", "r");
	FILE* fOut = fopen("out", "r");

	char ch1, ch2;
	while (fscanf(fIn, "%c", &ch1) == 1 && fscanf(fOut, "%c", &ch2) == 1) {
		if (table[ch1] == -1) {
			table[ch1] = ch2;
		} else {
			if (table[ch1] != ch2)
				fprintf(stderr, "FAIL\n");
		}
	}
	table['z'] = 'q';
	table['q'] = 'z';

	fclose(fIn);
	fclose(fOut);

	FILE* fInput = fopen("A-small-attempt1.in", "r");
	FILE* fOutput = fopen("A-small-attempt1.out", "w");

	int n;
	fscanf(fInput, "%d", &n);

	char line[100000];
	fgets(line, 100000, fInput);
	for (size_t i = 0; i < n; ++i) {
		fgets(line, 100000, fInput);
		fprintf(fOut, "Case #%d: ", i + 1);
		size_t len = strlen(line);
		for (size_t j = 0; j < len; ++j) {
			char chOut = table[line[j]];
			if (-1 == chOut)
				fprintf(stderr, "FAIL %c\n", line[j]);
			fprintf(fOutput, "%c", chOut);
		}
	}

	fclose(fInput);
	fclose(fOutput);

	return 0;
}