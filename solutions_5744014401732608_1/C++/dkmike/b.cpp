#include <iostream>

using namespace std;

const int MAXN = 51;

typedef unsigned long long ull;

ull upow(ull a, ull n) {
	ull r = 1;
	while (n) {
		if (n % 2) {
			r *= a;
		}
		n /= 2;
		a *= a;
	}
	return r;
}

ull ulog2(ull a) {
	ull res = 0;
	while (0 != a) {
		++res;
		a /= 2;
	}
	return res;
}

void solve(const int t) {
	int adj[MAXN][MAXN] = { {0, }, };
	ull B = 0, M = 0;
	cin >> B >> M;

	ull maxNum = upow(2, B - 2);
	if (maxNum < M) {
		cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		return;
	}

	cout << "Case #" << t << ": POSSIBLE" << endl;

	ull maxPow = ulog2(M);
	for (ull i = 0; i <= maxPow; ++i) {
		for (ull j = i + 1; j <= maxPow; ++j) {
			adj[i][j] = 1;
		}
	}

	adj[maxPow][B - 1] = 1;
	adj[B - 1][B - 1] = 0;

	ull rem = M - upow(2, maxPow - 1);
	ull iter = 1;
	while (0 != rem) {
		if (rem % 2) {
			adj[iter][B - 1] = 1;
		}
		rem /= 2;
		++iter;
	}

	for (ull i = 0; i < B; ++i) {
		for (ull j = 0; j < B; ++j) {
			cout << adj[i][j];
		}
		cout << endl;
	}
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}
