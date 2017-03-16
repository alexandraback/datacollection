#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int T, N;
int A, B, K;

void solve() {
	std::cin >> A >> B >> K;
	int cnt = 0;
	for (int i = 0; i < A; ++i)
		for (int j = 0; j < B; ++j)
			if ((i & j) < K) cnt++;
	std::cout << cnt << std::endl;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	std::cin >> T;
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}