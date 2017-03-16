#include <stdio.h>

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

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		char wb[10000];
		char input[10000];

		scanf("%s", input);
		wb[5000] = input[0];
		int sp = 5000;
		int ep = 5000;
		for (int i = 1; input[i]; i++) {
			if (input[i] >= wb[sp]) {
				sp--;
				wb[sp] = input[i];
			}
			else {
				ep++;
				wb[ep] = input[i];
			}
		}

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		wb[ep+1] = '\0';	
		printf("Case #%d: %s\n", ecount, wb + sp);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
