#include <bits/stdc++.h>

#define _DEBUG

using namespace std;

const int N = (int)1e5 + 1;
const int inf = (int)1e9 + 7;
const int M = 261;
const int K = 10;

void solve(int test) {
	int n, k;
	cin >> n >> k;
	cout << "Case #" << test << ":" << endl;
	int s = 1 << (n / 2 - 2);
	for (int i = 0, j = 0; j < s && i < k; ++i, ++j) {
		int p = 0;
		string s;
		s += "1";
		for (int p = 0; p < n / 2 - 2; ++p) {
			if ((1 << p) & j) {
				s += "1";
			} else {
				s += "0";
			}
		}
		s += "11";
		for (int p = 0; p < n / 2 - 2; ++p) {
			if ((1 << p) & j) {
				s += "1";
			} else {
				s += "0";
			}
		}
		s += "1";
		cout << s << ' ';
		for (int p = 2; p <= 10; ++p) {
			long long d = 1, w = 1;
			for (int r = n / 2 - 3; r >= 0; --r) {
				w *= p;
				if ((1 << r) & j) {
					d += w;
				}
			}
			w *= p;
			d += w;
			cout << d << ' ';
		}
		cout << endl;
	}
}

int main() {
#ifdef _DEBUG
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		solve(test);
	}
	return 0;
}