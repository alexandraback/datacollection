#include <bits/stdc++.h>

#define _DEBUG

using namespace std;

const int N = (int)1e5 + 1;
const int inf = (int)1e9 + 7;
const int M = 261;
const int K = 10;

void solve(int test) {
	int n;
	cin >> n;
	cout << "Case #" << test << ": ";
	if (n == 0) {
		cout << "INSOMNIA" << endl;
		return; 
	}
	vector<bool> u(K, 0);
	int k = 0;
	for (k = n; ; k += n) {
		int d = k;
		for (; d > 0; d /= K) {
			u[d % K] = 1;
		}
		bool q = 0;
		for (int i = 0; i < K; ++i) {
			if (!u[i]) {
				q = 1;
				break;
			}
		}
		if (!q) {
			break;
		}
	}
	cout << k << endl; 
}

int main() {
#ifdef _DEBUG
	freopen("A-large.in", "r", stdin);
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