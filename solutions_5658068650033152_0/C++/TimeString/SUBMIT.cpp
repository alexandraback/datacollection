#include <stdio.h>

int cal(int w, int k, int h) {
	if (k <= 2 * w - 2)
		return k;
	else if (k <= 3 * w - 4)
		return 2 * w - 2;
	else {
		int offset = k - (3 * w - 4);
		int x = offset / w;
		int xx = offset % w;
		int need = 2 * w - 2;
		need += x * 2;
		if (xx >= 1)
			need++;
		if (xx >= w - 1)
			need++;
		int hei = 3 + x;
		if (xx > 0)
			hei++;

		//printf("%d %d %d --> %d %d\n", w, k, h, need, hei);

		if (hei > h)
			return 9999999;
		else
			return need;
	}
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

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		
		int ea, eb, ek;
		scanf("%d%d%d", &ea, &eb, &ek);
		if (ea > eb) {
			int t = ea;
			ea = eb;
			eb = t;
		}
		if (ea <= 2)
			printf("Case #%d: %d\n", ecount, ek);
		else {
			int pun = -(ea * eb - 4 - ek);
			if (pun > 0)
				ek -= pun;
			else
				pun = 0;
			int ans = ek;
			for (int i = 3; i <= ea; i++) {
				int t = cal(i, ek, eb);
				if (t < ans)
					ans = t;
			}
			for (int i = 3; i <= eb; i++) {
				int t = cal(i, ek, ea);
				if (t < ans)
					ans = t;
			}
			//printf("%d %d\n", ans, pun);
			printf("Case #%d: %d\n", ecount, ans + pun);
		}
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
