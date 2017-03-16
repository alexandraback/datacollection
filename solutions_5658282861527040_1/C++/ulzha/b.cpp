#include <iostream>
using namespace std;

typedef long long ll;

int A, B, K;

void dump(const char *l, int x, int ix) {
	int i;

	cout << l << ' ';
	for (i = 31; i--; ) {
		if (i < ix) {
			cout << '.';
		} else {
			cout << (x >> i & 1);
		}
	}
	cout << endl;
}

ll count(int ia, int ib, int ik) {
	int i;
	int a = A ^ 1 << ia, b = B ^ 1 << ib, k = K ^ 1 << ik;
	ll r = 1;

	// dump("a", a, ia);
	// dump("b", b, ib);
	// dump("k", k, ik);
	// for (i = 0; i < ia || i < ib || i < ik; i++) {
	for (i = 0; i < 30; i++) {
		if (i < ik) {
			if (i < ia && i < ib) {
				r *= 4;
			} else if (i < ia || i < ib) {
				r *= 2;
			} else {
				r *= 1;
			}
		} else {
			if (i < ia && i < ib) {
				r *= (1 << i & k ? 1 : 3);
			} else if (i < ia) {
				r *= (1 << i & k ? (1 << i & b ? 1 : 0) : (1 << i & b ? 1 : 2));
			} else if (i < ib) {
				r *= (1 << i & k ? (1 << i & a ? 1 : 0) : (1 << i & a ? 1 : 2));
			} else {
				r *= ((1 << i & (a & b)) == (1 << i & k));
			}
		}
	}
	// cout << r << endl;

	return r;
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		ll r = 0;
		int ia, ib, ik;

		cin >> A >> B >> K;

		for (ia = 0; 1 << ia <= A; ia++) if (1 << ia & A) {
			for (ib = 0; 1 << ib <= B; ib++) if (1 << ib & B) {
				for (ik = 0; 1 << ik <= K; ik++) if (1 << ik & K) {
					r += count(ia, ib, ik);
				}
			}
		}

		cout << "Case #" << it << ": " << r << endl;
	}
}
