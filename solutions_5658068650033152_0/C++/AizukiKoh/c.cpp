#include <iostream>

using namespace std;

int solve(int N, int M, int K) {
	if (K <= 4) {
		return K;
	} else if (N <= 2 || M <= 2) { //囲えない
		return K;
	} else if (K < 8) {
		return K - 1;
	} else if (N * M - K <= 4) {
		return 2 * (N + M) - 4 - (N * M - K);
	} else if (N == 3 || M == 3) {
		if (K < 11) {
			return K - 2;
		} else if (K < 14) {
			return K - 3;
		} else {
			return K - 4;
		}
	} else {
		if (K < 10) {
			return K - 2;
		} else if (K < 12) {
			return K - 3;
		} else if (K < 14) {
			return K - 4;
		} else if (K < 16) {
			return K - 5;
		} else {
			return K - 6;
		}
	}
}

void answer(int X, int ans) {
	cout << "Case #" << X << ": " << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	int N, M, K;
	for (int i = 1; i <= T; ++i) {
		cin >> N >> M >> K;
		answer(i, solve(N, M, K));
	}
	cout.flush();
	return 0;
}
