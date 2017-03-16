#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;


bool f(int X, int R, int C) {
	if (X == 1) return true;
	if (R < X) return false;
	if (X >= 7) return false;
	if (R * C % X != 0) return false;
	if (X == 2) return true;
	if (X == 3) {
		if (C <= 1) return false;
		else return true;
	}
	if (X == 4) {
		if (C <= 2) return false;
		else return true;
	}
	if (X == 5) {
		if (C <= 2) return false;
		if (C >= 4) return true;
		if (R % 5 == 0 && R >= 10) return true;
		else return false;
	}
	if (X == 6) {
		if (C <= 3) return false;
		else return true;
	}
	assert(false);
}
void solve() {
	int X, R, C;
	cin >> X >> R >> C;
	if (R < C) swap(R, C);
	cout << (f(X, R, C) ? "GABRIEL" : "RICHARD") << endl;
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

