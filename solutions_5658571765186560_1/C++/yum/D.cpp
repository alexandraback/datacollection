#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<int(b); i++)

bool solve() {
	int X, R, C;
	cin >> X >> R >> C;
	int ar = R*C, mv = min(R, C), mw = max(R, C);
	if (X >= 7 || (ar % X) != 0) return false;
	if (X > mw) return false;
	if (mv == 1 && X <= 2) return true;
	int reqd = min(mw, mv+1) + mv - 1;
	return X < reqd;
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": " << (solve() ? "GABRIEL" : "RICHARD") << endl;
	}
}
