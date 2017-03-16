#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int c, cc, x, y, w;
	scanf("%d", &c);
	for (cc = 0; cc < c; cc++) {
		scanf("%d %d %d", &y, &x, &w);
		int ans = y * (x / w) + w;
		if (x % w == 0)
			ans--;
		printf("Case #%d: %d\n", cc + 1, ans);
	}
	return 0;
}
