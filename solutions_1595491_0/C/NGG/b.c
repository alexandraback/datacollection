#include <stdio.h>

int main(void) {
	int tn, ti;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int n, s, p, i, j, r = 0, k[4], s1, s2;
		scanf("%d %d %d", &n, &s, &p);
		k[0] = k[1] = k[2] = k[3] = 0;
		for (i = 0; i < n; i++) {
			int t, b, bs;
			scanf("%d", &t);
			switch (t%3) {
			case 0:
				b = t/3;
				bs = (t+3)/3;
				break;
			case 1:
				b = (t+2)/3;
				bs = (t+2)/3;
				break;
			case 2:
				b = (t+1)/3;
				bs = (t+4)/3;
				break;
			}
			if (b >= p && b <= 10 && (((t%3) == 0) || b >= 1)) {
				if (bs >= p && bs <= 10 && bs >= 2) k[3]++;
				else k[1]++;
			} else {
				if (bs >= p && bs <= 10 && bs >= 2) k[2]++;
				else k[0]++;
			}
		}
		for (s1 = 0; s1 <= k[1]; s1++) {
			for (s2 = 0; s2 <= k[2]; s2++) {
				int u;
				if (s1+s2 > s) continue;
				if (s-(s1+s2) > k[0]+k[3]) continue;
				u = k[1]-s1+s2+k[3];
				if (u > r) r = u;
			}
		}
		printf("Case #%d: %d\n", ti, r);
	}
	return 0;
}
