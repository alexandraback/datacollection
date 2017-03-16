#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int x, y;
string res;

void moveN() {
    res += "SN";
}
void moveS() {
    res += "NS";
}
void moveE() {
    res += "WE";
}
void moveW() {
    res += "EW";
}

void solve() {
    cin >> x >> y;
    res.clear();
    for (int i = 1; i <= abs(x); i++)
        if (x > 0)
            moveE();
        else
            moveW();
    for (int i = 1; i <= abs(y); i++)
        if (y > 0)
            moveN();
        else
            moveS();
    cout << res << endl;
}

int main() {

    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int T = 0, cnt = 0;
    cin >> T;
    while (T > 0) {
        --T;
        cout << "Case #" << ++cnt << ": ";
        solve();
    }

}
