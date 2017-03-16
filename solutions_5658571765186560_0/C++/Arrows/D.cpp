#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        int x, r, c;
        cin >> x >> r >> c;
        if(r > c) swap(r, c);
        bool res = false;
        if(x == 1) res = true;
        else if(x == 2) res = (r*c)%2 == 0;
        else if(x == 3) {
            if(r*c % 3 == 0) {
                if(r == 2 && c == 3 || r == 3 && c == 3 || r == 2 && c == 6 ||
                        r == 3 && c == 4 || r == 3 && c == 5) {
                    res = true;
                }
            }
        } else {
            if(r*c % 4 == 0) {
                if(r == 3 && c == 4 || r == 4 && c == 4) {
                    res = true;
                }
            }
        }
        if(res) cout << "Case #" << cas << ": GABRIEL" << endl;
        else cout << "Case #" << cas << ": RICHARD" << endl;
    }
    return 0;
}
