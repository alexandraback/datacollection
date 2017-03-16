#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	char input[3000];

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		int cnts[256];
		for (int i = 0; i < 256; i++)
			cnts[i] = 0;

		scanf("%s", input);
		for (int i = 0; input[i]; i++)
			cnts[input[i]]++;

		int ac[10];
		ac[0] = cnts['Z'];
		ac[2] = cnts['W'];
		ac[4] = cnts['U'];
		ac[6] = cnts['X'];
		ac[8] = cnts['G'];
		ac[5] = cnts['F'] - ac[4];
		ac[7] = cnts['S'] - ac[6];
		ac[3] = cnts['T'] - ac[8] - ac[2];
		ac[1] = cnts['O'] - ac[0] - ac[2] - ac[4];
		ac[9] = (cnts['N'] - ac[1] - ac[7]) / 2;

		printf("Case #%d: ", ecount);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < ac[i]; j++)
				printf("%d", i);
		printf("\n");
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
