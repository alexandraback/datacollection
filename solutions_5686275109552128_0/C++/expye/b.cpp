#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int inf = ~0u>>1;
int T;
int a[1001], d;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &d);
		int amax = 0;
		for (int j = 1; j <= d; j++) {
			scanf("%d", &a[j]);
			if (a[j] > amax) amax = a[j];
		}
		int ans = inf;
		for (int j = 1; j <= amax; j++) {
			int cnt = 0;
			for (int k = 1; k <= d; k++) {
				cnt += (a[k] - 1) / j;
			}
			if (cnt + j < ans) ans = cnt + j;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
