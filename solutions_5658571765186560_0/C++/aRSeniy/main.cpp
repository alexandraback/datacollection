#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc() {

}

void solve() {
    int x, r, c;
    cin >> x >> r >> c;
    if (x == 1) {
        cout << "GABRIEL" << endl;
        return;
    }
    if (x == 2) {
        if (r % 2 == 0 || c % 2 == 0) {
            cout << "GABRIEL" << endl;
        } else {
            cout << "RICHARD" << endl;
        }
        return;
    }
    if (x == 3) {
        if ((r == 1 || c == 1) || (r % 3 && c % 3)) {
            cout << "RICHARD" << endl;
        } else {
            cout << "GABRIEL" << endl;
        }
        return;
    }
    if (x == 4) {
        if (r * c < 12) {
            cout << "RICHARD" << endl;
        } else {
            cout << "GABRIEL" << endl;
        }
        return;
    }
    if (x > 6) {
        cout << "RICHARD" << endl;
        return;
    }
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    precalc();

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cerr << test << endl;
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
