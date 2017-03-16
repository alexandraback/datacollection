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

		
		int ek, ec, es;
		scanf("%d%d%d", &ek, &ec, &es);
		if (es * ec < ek)
			printf("Case #%d: IMPOSSIBLE\n", ecount);
		else {
			printf("Case #%d:", ecount);
			int cnt = 0;
			for (int i = 0; i < es && cnt < ek; i++) {
				long long int n = 0;
				for (int j = 0; j < ec; j++) {
					int t = cnt;
					if (t >= ek)
						t = ek-1;
					n = n * ek + t;
					cnt++;
				}
				printf(" %lld", n+1);
			}
			printf("\n");
		}
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
