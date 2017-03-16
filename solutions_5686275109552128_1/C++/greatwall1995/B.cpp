#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1111;

int n;
int p[N];
int mx, ans;

void update(int p0) {
	int tmp = p0;
	for (int i = 1; i <= n; ++i) {
		tmp += (p[i] - 1) / p0;
	}
	ans = min(ans, tmp);
}

int main() {
	freopen("B_.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int T = 1; T <= TT; ++T) {
		scanf("%d", &n);
		mx = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", p + i);
			mx = max(mx, p[i]);
		}
		ans = mx;
		for (int p0 = 1; p0 <= mx; ++p0) {
			update(p0);
		}
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}
