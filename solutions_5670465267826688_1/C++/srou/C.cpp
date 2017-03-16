#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

enum Quaternions {ONE, I, J, K};

struct Number {
	bool sign;
	Quaternions q;

	Number() : sign(false), q(ONE) {}

	Number(Quaternions q, bool sign = false) : sign(sign), q(q) {}

	Number(char c) : sign(false) {
		if (c == 'i') q = I;
		else if (c == 'j') q = J;
		else if (c == 'k') q = K;
		else assert(false);
	}

	Number operator*(const Number &n) const {
		Number ret;
		ret.sign = sign ^ n.sign;
		if (q == ONE) ret.q = n.q;
		else if (n.q == ONE) ret.q = q;
		else if (q == I) {
			if (n.q == I) {
				ret.sign = !ret.sign;
				ret.q = ONE;
			} else if (n.q == J) {
				ret.q = K;
			} else if (n.q == K) {
				ret.sign = !ret.sign;
				ret.q = J;
			}
		} else if (q == J) {
			if (n.q == I) {
				ret.sign = !ret.sign;
				ret.q = K;
			} else if (n.q == J) {
				ret.sign = !ret.sign;
				ret.q = ONE;
			} else if (n.q == K) {
				ret.q = I;
			}
		} else if (q == K) {
			if (n.q == I) {
				ret.q = J;
			} else if (n.q == J) {
				ret.sign = !ret.sign;
				ret.q = I;
			} else if (n.q == K) {
				ret.sign = !ret.sign;
				ret.q = ONE;
			}
		}
		return ret;
	}

	bool operator==(const Number &n) const {
		return sign == n.sign && q == n.q;
	}

	bool operator!=(const Number &n) const {
		return !(*this == n);
	}
};

ostream& operator<<(ostream& os, const Number &n) {
	if (n.sign) os << "-";
	switch(n.q) {
		case ONE:
		os << "1";
		break;
		case I:
		os << "I";
		break;
		case J:
		os << "J";
		break;
		case K:
		os << "K";
		break;
	}
	return os;
};

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t<T; ++t) {
		int L, X;
		long long _X;
		scanf("%d %lld", &L, &_X);
		X = _X % 4;
		for (int i = 0; i<3 && _X > 3; ++i, _X-=4, X+=4);
		char buff[10010];
		scanf(" %s", buff);


		Number n(ONE);
		Number next(I);
		bool ok = true;
		int i = 0;
		for(; n != next && i < L*X; ++i) {
			n = n * Number(buff[i % L]);
//			cout << n;
		}
		ok = ok && n == next;
//		cout << endl << ok << endl;

		n = Number(ONE);
		next = Number(J);
		for(; n != next && i < L*X; ++i) {
			n = n * Number(buff[i % L]);
//			cout << n;
		}
		ok = ok && n == next;
//		cout << endl << ok << endl;

		n = Number(ONE);
		next = Number(K);
		for(; i < L*X; ++i) {
			n = n * Number(buff[i % L]);
//			cout << n;
		}
		ok = ok && n == next;

		printf("Case #%d: %s\n", t+1, ok ? "YES" : "NO");
	}
	return 0;
}
