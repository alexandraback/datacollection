#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int ecase, ecount;
	int en;
	int einfo[101];
	int ea;

	int ans;

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		scanf("%d%d", &ea, &en);
		for (int i = 0; i < en; i++)
			scanf("%d", &einfo[i]);
		sort(einfo, einfo+en);

		ans = en;
		if (ea != 1) {
			int tans = 0;
			for (int i = 0; i < en; i++) {
				int t = tans + en - i;
				if (t < ans)
					ans = t;
				while (ea <= einfo[i]) {
					ea += ea-1;
					tans++;
				}
				ea += einfo[i];
			}
			if (tans < ans)
				ans = tans;
		}
		printf("Case #%d: %d\n", ecount, ans);
	}

	return 0;
}
