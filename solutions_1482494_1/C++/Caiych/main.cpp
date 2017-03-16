#include <stdio.h>
#include <cstring>

using namespace std;

int n,a[1100],b[1100],flag[1100];

int main() {
	int T;
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d",&n);
		for (int i = 0;i < n;i++) 
			scanf("%d%d",&a[i],&b[i]);
		int cur = 0,ans = 0;
		memset(flag,0,sizeof(flag));
		while (cur < 2 * n) {
			bool nn = false;
			for (int j = 0;j < n;j++) {
				if (flag[j] < 2 && cur >= b[j]) {
					nn = true;
					cur += 2-flag[j];
					ans++;
					flag[j] = 2;
				}
			}
			if (!nn) {
				int x = -1;
				for (int j = 0;j < n;j++) {
					if (flag[j] == 0) {
						if (a[j] <= cur && (x == -1 || b[j] - a[j] > b[x] - a[x]))
							x = j;
					}
				}
				if (x == -1) {
					ans = -1;
					break;
				} else {
					ans++;
					cur++;
					flag[x] = 1;
				}
			}
		}
		printf("Case #%d: ",cas);
		if (ans == -1) printf("Too Bad\n");
		else printf("%d\n",ans);
	}
	return 0;
}
