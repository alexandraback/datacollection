#include <stdio.h>
#include <string>
#include <map>

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

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		int num;
		scanf("%d", &num);
		
		string a[1000], b[1000];
		for (int i = 0; i < num; i++) {
			char ta[1000], tb[1000];
			scanf("%s%s", ta, tb);
			a[i] = string(ta);
			b[i] = string(tb);
		}

		int ans = 0;
		for (int i = 0; i < (1 << num); i++) {
			map<string, int> existed;
			for (int j = 0; j < num; j++) {
				if (i & (1 << j)) {
					string combine = a[j] + " " + b[j];
					existed[combine] = 1;
				}
			}
			//printf("i=%d\n", i);
			int cnt = 0;
			bool pass = true;
			for (int j = 0; j < num && pass; j++)
				if (!(i & (1 << j))) {
					//printf("  j=%d\n", j);
					bool find = false;
					for (int k = 0; k < num && !find; k++)
						if (i & (1 << k))
							for (int l = 0; l < num && !find; l++)
								if (l != k && (i & (1 << l))) {
									//printf("  j=%d k=%d l=%d\n", j, k, l);
									if (a[j] == a[k] && b[j] == b[l]) {
										string combine = a[j] + " " + b[j];
										if (existed.find(combine) == existed.end())
											find = true;
									}
								}
					if (find == false)
						pass = false;
					cnt++;
				}
			if (pass && cnt > ans)
				ans = cnt;
		}
		printf("Case #%d: %d\n", ecount, ans);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
