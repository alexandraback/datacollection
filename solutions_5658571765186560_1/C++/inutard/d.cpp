#include <bits/stdtr1c++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
        int X, R, C; cin >> X >> R >> C;
        
        if (R > C) swap(R,C);
        
        bool gab = false;
        if (X == 1) {
            gab = true;
        } else if (X == 2) {
            gab = true;
        } else if (X == 3) {
            if (R >= 2 && C >= 2) gab = true;
        } else if (X == 4) {
            if (R >= 3 && C >= 4) gab = true;
        } else if (X == 5) {
            if (R == 3 && C >= 10) gab = true;
            else if (R >= 4 && C >= 4) gab = true;
        } else if (X == 6) {
            if (R >= 4) gab = true;
        }
        gab = gab && ((R*C)%X == 0);
        cout << "Case #" << ca << ": " << (gab ? "GABRIEL" : "RICHARD") << endl;
    }
	return 0;
}