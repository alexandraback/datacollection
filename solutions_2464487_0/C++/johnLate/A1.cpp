#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)


int TC;
ll R, T;

bool eval(ll Q) {
	return 2*Q + 2*R - 1 <= T/Q;
}

int main() {
	int TC; cin >> TC;
	FOR(tc,1,TC+1) {
		cin >> R >> T;

		ll A = 1;
		ll B = LLONG_MAX/4;

		ll Q = 1;
		while (A <= B) {
			ll M = (A + B)/2;
			if (eval(M)) { Q = M; A = M+1; }
			else         { B = M-1; }
		}

		printf("Case #%d: %lld\n", tc, Q);
	}
}
