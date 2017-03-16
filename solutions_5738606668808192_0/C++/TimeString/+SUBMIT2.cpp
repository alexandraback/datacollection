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
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		int len, n;
		scanf("%d%d", &len, &n);

		char in_name[1000];
		sprintf(in_name, "c_database_%d.txt", len);
		FILE *fin = fopen(in_name, "r");
		char line[1000];
		
		printf("Case #%d:\n", ecount);
		
		while (n > 0) {
			fgets(line, 1000, fin);
			printf("%s", line);
			n--;
		}

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
