#include <stdio.h>

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

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

	char line[1000];
	gets(line);
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);


		gets(line);
		long long a, b;
		sscanf(line, "%lld/%lld", &a, &b);
		//printf("%lld %lld\n", a, b);
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		//printf("%lld %lld\n", a, b);
		
		int ans = 0;
		int at = 0;
		while (b % 2 == 0) {
			b /= 2;
			ans++;
			a /= 2;
			if (a > 0)
				at++;
		}

		if (b > 1)
			printf("Case #%d: impossible\n", ecount);
		else
			printf("Case #%d: %d\n", ecount, ans - at);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
