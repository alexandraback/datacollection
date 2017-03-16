#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, a[1100];

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 1000;
		for (int l = 1; l <= 1000; l++) {
			int tot = 0;
			for (int i = 1; i <= n; i++)
				tot += (a[i] - 1) / l;
			ans = min(ans, tot + l);
		}
		printf("Case #%d: %d\n", k, ans);
	}

}
