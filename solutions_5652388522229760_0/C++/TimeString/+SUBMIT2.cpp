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

	int goal = (1 << 10) - 1;
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		long long n;
		scanf("%lld", &n);
		if (n == 0)
			printf("Case #%d: INSOMNIA\n", ecount);
		else {
			int appear = 0;
			long long ans;
			for (ans = n; appear != goal; ans += n) {
				long long t = ans;
				while (t > 0) {
					int tt = t % 10;
					appear |= (1 << tt);
					t /= 10;
				}
			}
			ans -= n;
			printf("Case #%d: %lld\n", ecount, ans);
		}
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
