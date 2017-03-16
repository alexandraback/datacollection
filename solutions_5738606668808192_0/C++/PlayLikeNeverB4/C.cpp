#include <bits/stdc++.h>

using namespace std;

int N, J;
long long D[11];

long long calcInBase(int n, int b) {
	long long ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		ret *= b;
		if ((n & (1 << i)) > 0) {
			ret++;
		}
	}
	return ret;
}

int getDivisor(long long n) {
	for (int d = 2; (long long) d * d <= n; d++) {
		if (n % d == 0) {
			return d;
		}
	}
	return -1;
}

string toBinaryString(int n) {
	string ret(N, '0');
	for (int i = N - 1; i >= 0; i--) {
		if ((n & (1 << i)) > 0) {
			ret[N - 1 - i] = '1';
		}
	}
	return ret;
}

void solve() {
	int need = J;
	for (int mid = 0; mid < (1 << (N - 2)) && need > 0; mid++) {
		int low = (mid << 1) | 1;
		int n = (1 << (N - 1)) | low;

		bool ok = true;
		for (int b = 2; b <= 10; b++) {
			long long nb = calcInBase(n, b);
			int d = getDivisor(nb);
			D[b] = d;

			if (d == -1) {
				ok = false;
			}
		}

		if (ok) {
			cout << toBinaryString(n);
			for (int b = 2; b <= 10; b++) {
				cout << ' ' << D[b];
			}
			cout << '\n';
			need--;
		}
	}
	assert(need == 0);
}

int main() {
	assert(freopen("C.in", "r", stdin));
	assert(freopen("C.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":\n";

		cin >> N >> J;
		solve();
		
		cerr << t << endl;
	}

	// for (int b = 2; b <= 10; b++) {
	// 	int nb = calcInBase(9, b);
	// 	cerr << nb << ' ';
	// }
	// cerr << endl;
	// for (int b = 2; b <= 10; b++) {
	// 	int nb = calcInBase(9, b);
	// 	int d = getDivisor(nb);
	// 	cerr << d << ' ';
	// }

	return 0;
}
