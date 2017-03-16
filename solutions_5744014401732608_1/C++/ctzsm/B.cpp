#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int b[55][55];
void solve() {
	long long B, M;
	cin >> B >> M;
	long long maxM = 1ll << (B - 2);
	if (maxM < M) {
		printf("IMPOSSIBLE\n");
		return;
	}
	memset(b, 0, sizeof b);
	set<int> p;
	for (int i = B - 1; i > 0; --i) {
		int j = max(0, i - 2);
		long long x = 1ll << j;
		if (x <= M) {
			M -= x;
			b[i][B] = 1;
			for (int k = 1; k <= i; ++k) p.insert(k);
		}
	}
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it) {
		for (int j = 1; j < *it; ++j)
			b[j][*it] = 1;
	}
	printf("POSSIBLE\n");
	for (int i = 1; i <= B; ++i) {
		for (int j = 1; j <= B; ++j) printf("%d", b[i][j]);
		printf("\n");
	}
}
int main() {
	// freopen("in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
