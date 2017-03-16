#include <stdio.h>
char inp[100010];
int main() {
	int cas, n;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d%s", &n, inp);
		int ans = 0, cur = 0;
		for (int i=0; i<=n; i++) {
			if (inp[i] > '0') {
				if (cur < i) {
					ans += i-cur;
					cur =i;
				}
				cur += inp[i] - '0';
			}
		}
		printf("Case #%d: %d\n", ii+1, ans);
	}
	return 0;
}
