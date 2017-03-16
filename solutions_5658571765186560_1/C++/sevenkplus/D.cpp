#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

bool ff(int p, int n, int m) {
	if (p >= 7) return 1;
	if (n > m) swap(n, m);
	if (n*m%p != 0) return 1;
	if (p == 1) {
		return 0;
	}
	if (p == 2) {
		return 0;
	}
	if (p == 3) {
		if (n == 1) return 1;
		return 0;
	}
	if (p == 4) {
		if (n <= 2) return 1;
		return 0;
	}
	if (p == 5) {
		if (n <= 2) return 1;
		return 0;
	}
	if (p == 6) {
		if (n <= 2) return 1;
		if (n == 3) return 1;
		return 0;
	}
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int p, n, m;
		cin >> p >> n >> m;
		printf ("Case #%d: %s\n", __, ff(p,n,m)?"RICHARD":"GABRIEL");
	}
	return 0;
}
