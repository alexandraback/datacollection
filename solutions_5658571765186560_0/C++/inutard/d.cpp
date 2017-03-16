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
        
        bool gab = false;
        if (X == 1) {
            gab = true;
        } else if (X == 2) {
            if ((R*C)%2 == 0) gab = true;
        } else if (X == 3) {
            if (R >= 2 && C >= 2 && (R*C)%3 == 0) gab = true;
        } else if (X == 4) {
            if (min(R,C) >= 3 && max(R,C) >= 4 && (R*C)%4 == 0) gab = true;
        }
        cout << "Case #" << ca << ": " << (gab ? "GABRIEL" : "RICHARD") << endl;
    }
	return 0;
}