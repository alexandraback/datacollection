#include <cstdio>
int T, r, c, w, ans;
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d%d%d", &r, &c, &w);
		ans = r * c / w;
		if (c % w == 0) ans += w - 1;
		else ans += w;
		printf("Case #%d: %d\n", Ti, ans);
	}
	return 0;
}
