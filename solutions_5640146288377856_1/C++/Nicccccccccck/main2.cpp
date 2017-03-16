#include <cstdio>
int R, C, W;
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output", "w", stdout);
	int T, cnt = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &R, &C, &W);
		int ans = 0;
		ans += C/W*R;
		if(C%W) ans += W;
		else ans += W-1;
		printf("Case #%d: %d\n", ++cnt, ans);
	}
	return 0;
}