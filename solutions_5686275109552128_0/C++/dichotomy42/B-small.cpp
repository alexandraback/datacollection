#include <cstdio>
#include <cstdlib>

using namespace std;

int T, D;
int P[1005];

int max(int a, int b) {
	return (a > b ? a : b);
}

int min(int a, int b) {
	return (a < b ? a : b);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small0.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		int maxP = 0, ans = 1005;
		scanf("%d", &D);
		for (int i = 0; i < D; ++ i) {
			scanf("%d", &P[i]);
			maxP = max(maxP, P[i]);
		}
		for (int k = 1; k <= maxP; ++ k) {
			int sum = 0;
			for (int j = 0; j < D; ++ j)
				sum += (int)((P[j] + k - 1) / (double)k) - 1;
			ans = min(ans, sum + k);
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
