#include <cstdio>
typedef long long LL;
// int dp[21][21];
// int ac(int col, int wit) {
// 	if (dp[col][wit]) return dp[col][wit];
// 	if ()
// }
main()
{
	int t, r, c, w, cs = 0, ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &r, &c, &w);
		ans = r * (c / w) + w - 1;
		if (c % w) ++ans;
		printf("Case #%d: %d\n", ++cs, ans);
	}
}