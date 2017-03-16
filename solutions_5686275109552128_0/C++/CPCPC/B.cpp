#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1005;
int T, n, ans, a[N];
int main() {
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &n);
		ans = N;
		for (int i = 0; i < n; i++) scanf("%d", a+i);
		for (int i = 1; i < N; i++) {
			int t = i;
			for (int j = 0; j < n; j++) t += (a[j]-1)/i;
			ans = min(ans, t);
		}
		printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}
