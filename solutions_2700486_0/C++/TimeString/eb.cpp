#include <stdio.h>


double xinfo[600];
double info2[600];

inline int f(int n) {
	return 2 * n * (n+1) + n + 1;
}

inline double c(int a, int b) {
	return xinfo[a] / xinfo[b] / xinfo[a-b];
}

int main() {
	int ecase, ecount;

	xinfo[0] = 1.0;
	info2[0] = 1.0;
	for (int i = 1; i < 600; i++) {
		xinfo[i] = xinfo[i-1] * i;
		info2[i] = info2[i-1] * 2.0;
	}

	int en, ex, ey;

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		scanf("%d%d%d", &en, &ex, &ey);
		if (ex < 0)
			ex = -ex;

		int lev = (ex + ey) / 2;
		int inside = f(lev-1);
		int outside = f(lev);

		if (en <= inside)
			printf("Case #%d: 0.0\n", ecount);
		else if (en >= outside)
			printf("Case #%d: 1.0\n", ecount);
		else if (ex == 0)
			printf("Case #%d: 0.0\n", ecount);
		else {
			double ans = 0.0;
			int remain = en - inside;
			for (int i = 0; i <= remain; i++) {
				/*//ans += c(remain, i) / info2[remain];
				int left = i - ey - 1;
				if (left < lev * 2) {
					ans += c(i-1, ey) / info2[i-1] / 2.0;
					//printf("A: c(%d,%d)=%lf / %lf / 2.0= %lf\n", i-1,ey, c(i-1,ey),info2[i-1],c(i-1, ey) / info2[i-1] / 2.0);
				}
				else {
					for (int j = lev * 2; j < i; j++) {
						ans += c(j, lev*2) / info2[j];
						//printf("B: c(%d,%d)=%lf / %lf = %lf\n", j,lev*2, c(j,lev*2),info2[j],c(j, lev*2) / info2[i]);
					}
				}*/
				int left = remain - i;
				int right = i;
				if (left > lev * 2) {
					left = lev * 2;
					right = remain - left;
				}
				if (right > lev * 2) {
					right = lev * 2;
					left = remain - right;
				}
				if (right >= ey+1)
					ans += c(remain, i) / info2[remain];
			}
			printf("Case #%d: %.8lf\n", ecount, ans);
		}
	}

	return 0;
}
