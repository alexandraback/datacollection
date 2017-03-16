#include <stdio.h>

int main() {
	int ecount, ecase;
	int ea[1010][2];
	bool u[1010][2];
	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		int en;
		scanf("%d", &en);
		for (int i = 0; i < en; i++) {
			scanf("%d%d", &ea[i][0], &ea[i][1]);
			u[i][0] = false;
			u[i][1] = false;
		}
		int ans = 0;
		int now = 0;
		int r1 = en;
		bool failedFlag = false;
		while (r1 > 0) {
			int i, j;
			for (i = 0; i < en; i++)
				if (u[i][1] == false && now >= ea[i][1]) {
					break;
				}
			if (i < en) {
				ans++;
				now++;
				//printf("%d-b\n", i);
				u[i][1] = true;
				if (u[i][0] == false) {
					u[i][0] = true;
					now++;
				}
				r1--;
			}
			else {
				int candi = -1;
				int max = 0;
				for (j = 0; j < en; j++)
					if (u[j][0] == false && now >= ea[j][0] && ea[j][1] > max) {
						candi = j;
						max = ea[j][1];
					}
				if (candi != -1) {
					//printf("%d-a\n", j);
					ans++;
					now++;
					u[candi][0] = true;
				}
				else {
					failedFlag = true;
					break;
				}
			}
		}
		if (failedFlag)
			printf("Case #%d: Too Bad\n", ecount);
		else
			printf("Case #%d: %d\n", ecount, ans);
	}
	return 0;
}
