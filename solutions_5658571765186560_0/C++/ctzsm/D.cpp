#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const char aR[10] = "RICHARD", aG[10] = "GABRIEL";
void solve() {
	int X, R, C; scanf("%d%d%d", &X, &R, &C);
	// printf("\n%d %d %d\n", X, R, C);
	if (R < C) swap(R, C);
	if (X >= 7 || ((R * C) % X) || X > R) {
		printf("%s\n", aR);
		return;
	}
	int lr = X / 2 + 1, lc = X / 2 + (X & 1);
	if (lr > R || lc > C) {
		printf("%s\n", aR);
		return;
	}
	if (X == 4 && R == 4 && C == 2) {
		printf("%s\n", aR);
		return;
	}
	printf("%s\n", aG);
}
int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}