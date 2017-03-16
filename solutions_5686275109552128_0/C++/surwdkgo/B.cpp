#include <stdio.h>
#include <algorithm>
int inp[1010];
int n;
int main() {
	int cas;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%d", &inp[i]);
		}
		std::sort(inp, inp+n);
		int ans = 1010;
		for (int mx = 1; mx <= 1000; mx++) {
			int cur = 0;
			for (int i=0; i<n; i++) {
				cur += (inp[i]-1) / mx;
			}
			ans = std::min(ans, cur+mx);
		}
		printf("Case #%d: %d\n", ii+1, ans);
	}
	return 0;
}
