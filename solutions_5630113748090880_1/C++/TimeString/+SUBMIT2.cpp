#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int n;

struct R {
	int d[50];
	bool operator < (const R &r) {
		for (int i = 0; i < n; i++)
			if (d[i] != r.d[i])
				return d[i] < r.d[i];
		return false;
	}
};

R rows[100];

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

		map<int, int> cnt;

		scanf("%d", &n);
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int t;
				scanf("%d", &t);
				rows[i].d[j] = t;
				if (cnt.find(t) == cnt.end())
					cnt[t] = 1;
				else
					cnt.erase(t);
			}
		}
		printf("Case #%d:", ecount);
		for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
			printf(" %d", it->first);
		printf("\n");

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
