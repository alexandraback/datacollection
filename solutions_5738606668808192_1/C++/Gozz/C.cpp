#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

vector<int> sieve(int P) {
	vector<bool> prime(P, true);
	vector<int> res;
	prime[0] = prime[1] = false;
	for (int p = 0; p < P; ++p) {
		if (prime[p]) {
			res.push_back(p);
			for (int i = 2 * p; i < P; i += p) {
				prime[i] = false;
			}
		}
	}
	return res;
}

int main() {
	int T, N, J;
	cin >> T >> N >> J;
	i64 bs = 0;
	i64 lb = 1;
	i64 hb = 1 << (N-1);
	vector<int> primes = sieve(10000);
	cout << "Case #1:" << endl;
	while (J > 0) {
		++bs;
		if (bs >= (1 << (N-2))) break;
		i64 v = hb | (bs << 1) | lb;
		vector<int> factors(11, -1);
		for (int b = 2; b <= 10; ++b) {
			for (int p : primes) {
				i64 val = 0;
				for (int i = N-1; i >= 0; --i) {
					val *= b;
					if (v & (1 << i)) val += 1;
					val %= p;
				}
				if (val % p == 0) {
					factors[b] = p;
					break;
				}
			}
		}
		bool isvalid = true;
		for (int b = 2; b <= 10; ++b) {
			if (factors[b] == -1) {
				isvalid = false;
				break;
			}
		}
		if (isvalid) {
			for (int i = N - 1; i >= 0; --i) {
				if (v & (1 << i)) cout << "1";
				else cout << "0";
			}
			for (int b = 2; b <= 10; ++b) {
				cout << " " << factors[b];
			}
			cout << endl;
			--J;
		}
	}
	return 0;
}