#include <stdio.h>
#include <algorithm>

using namespace std;

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

	double ea[10000];
	double eb[10000];
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		
		int en;
		scanf("%d", &en);
		for (int i = 0; i < en; i++)
			scanf("%lf", &ea[i]);
		for (int i = 0; i < en; i++)
			scanf("%lf", &eb[i]);

		int ansa = 0, ansb = 0;
		sort(ea, ea + en);
		sort(eb, eb + en);
		int ah, at;
		int bh, bt;
	/*	
		for (int i = 0; i < en; i++)
			printf("%.3lf ", ea[i]);
		printf("\n");
		for (int i = 0; i < en; i++)
			printf("%.3lf ", eb[i]);
		printf("\n");
	*/	
		ah = 0;
		at = en - 1;
		bh = 0;
		bt = en - 1;
		for (int i = en - 1; i >= 0; i--) {
			if (eb[bt] > ea[i]) {
				bt--;
			}
			else {
				bh++;
				ansa++;
			}
		}
		
		ah = 0;
		at = en - 1;
		bh = 0;
		bt = en - 1;
		for (int i = en - 1; i >= 0; i--) {
			if (ea[at] > eb[i]) {
				ansb++;
				at--;
			}
		}

		printf("Case #%d: %d %d\n", ecount, ansb, ansa);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
