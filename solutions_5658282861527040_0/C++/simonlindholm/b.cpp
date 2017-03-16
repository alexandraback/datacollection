#include <iostream>
#include <vector>
using namespace std;

struct S {
	int high;
	int m;
	S(int high, int m) : high(high), m(m) {}
	bool known(int b) const { return b >= m; }
	int all(int b) const { return known(b) ? 1 : 2; }
	int truthy(int b) const { return known(b) ? (high & b ? 1 : 0) : 1; }
};
vector<S> split(int N) {
	vector<S> res;
	int high = 0;
	for (int m = 1 << 30; m; m >>= 1) {
		if (N & m) {
			res.emplace_back(high, m);
			high |= m;
		}
	}
	return res;
}

long long solve(int A, int B, int K) {
	long long res = 0;
	for (S sa : split(A)) {
		for (S sb : split(B)) {
			for (S sk : split(K)) {
				long long w = 1;
				for (int b = 1 << 30; b; b >>= 1) {
					if (sk.known(b)) {
						int tw = sa.truthy(b) * sb.truthy(b);
						if (sk.high & b)
							w *= tw;
						else
							w *= sa.all(b) * sb.all(b) - tw;
					}
					else {
						w *= sa.all(b) * sb.all(b);
					}
				}
				res += w;
			}
		}
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int A, B, K;
		cin >> A >> B >> K;
		cout << "Case #" << i << ": " << solve(A, B, K) << endl;
	}
}
