#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int t, d, p[1010], ans;

int main()
{
	scanf("%d", &t);
	for (int nCase = 1; nCase <= t; ++nCase) {
		scanf("%d", &d);
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= d; ++i)
			scanf("%d", &p[i]);
		int maxp = 0;
		for (int i = 1; i <= d; ++i)
			maxp = max(maxp, p[i]);
		ans = 0x3f3f3f3f;
		for (int i = 1; i <= maxp; ++i) {
			int time = 0;
			for (int j = 1; j <= d; ++j)
				time += (p[j] - 1) / i;
			ans = min(ans, time + i);
		}
		printf("Case #%d: %d\n", nCase, ans);
	}
	return 0;
}
