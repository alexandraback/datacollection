#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int calc(int n, int m, int K) {
	int base = 2 * (n - 2);
	if (K < base) {
		return K;
	}

	int left = K - base;
	int i = left / n;
	if (left > i * n) ++i;
	int result = base + 2 * i;
	result = std::min(result, K);
	return result;
}

int c(int n, int m, int K) {
	int r = calc(n, m, K);
	int r2 = calc(n, m, K - 1);
	if (r2 + 1 < r) r = r2 + 1;
	return r;
}

void solveCase() {
	int N, M, K;
	cin >> N >> M >> K;
	int n = std::min(N, M);
	int m = std::max(N, M);
	if (n <= 2) {
		cout << K;
		return;
	}
	int result = 0;
	if (K >= N*M - 4) {
		result = 2 * (N + M) - 4;
		result -= N*M - K;
	}
	else {
		result = c(n, m, K);
		int r3 = c(n - 1, m, K);
		if (r3 < result) result = r3;
	}
	cout << result;
}

int main() {
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	int T;
	std::cin >> T;
	for (int i = 1; i < T + 1; ++i)
	{
		std::cout << "Case #" << i << ": ";
		solveCase();
		if (i < T)
			std::cout << std::endl;
	}
	return 0;
}