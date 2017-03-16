#include <iostream>
using namespace std;

static int solve(int r, int c, int w) {
	if (w == 1)
		return r * c;
	if (c % w == 0)
		return (r * (c / w) + w - 1);
	return (r * (c / w) + w);
}

int main()
{
	int T, t;
	int R, C, W;
	int ans;
	scanf("%d\n", &T);
	for (t = 1; t <= T; ++t) {
		ans = 0;
		scanf("%d %d %d\n", &R, &C, &W);
		ans = solve(R, C, W);
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}