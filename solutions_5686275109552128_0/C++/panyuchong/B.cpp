#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = (int) 1e3, inf = 0x7f7f7f7f;

int P[MAXN + 10];

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		int D;
		scanf("%d", &D);
		int Pmax = 0;
		for (int i = 1; i <= D; i++) {
			scanf("%d", &P[i]);
			Pmax = max(Pmax, P[i]);
		}
		int ans = inf;
		for (int i = 1; i <= Pmax; i++) {
			int temp = 0;
			for (int j = 1; j <= D; j++)
				if (P[j] > i)
					temp += (P[j] - i) / i - !((P[j] - i)  % i) + 1;
			ans = min(ans, temp + i);
		}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}