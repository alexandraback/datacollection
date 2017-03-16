#include <cstdio>
#include <algorithm>
using namespace std;
int n, P[1005];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) scanf("%d", P + i);
		sort(P + 1, P + n + 1);
		int res = 1e9;
		for (int Max = 1; Max <= 1000; Max++) {
			int s = 0, ok = 1;
			for (int i = 1; i <= n; i++) s += (P[i] - 1) / Max;
			if (res > Max + s) res = Max + s;
		}
		printf("Case #%d: %d\n", run, res);
	}
	fcloseall();
	return 0;
}