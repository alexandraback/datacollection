#include <cstdio>
#include <cstdlib>

using namespace std;

int T, n;
char sh[1005];
int shy[1005];

int max(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small0.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		scanf("%d %s", &n, sh);
		for (int i = 0; i < n + 1; ++ i)
			shy[i] = sh[i] - '0';
		int ans = 0, cnt = shy[0];
		for (int i = 1; i < n + 1; ++ i) {
			if (!shy[i]) continue;
			int need = i - cnt;
			cnt += shy[i];
			if (need <= 0) continue;
			ans += need;
			cnt += need;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
