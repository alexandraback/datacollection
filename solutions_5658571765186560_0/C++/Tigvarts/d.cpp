#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int x, r, c;
    cin >> x >> r >> c;
    //cout << x << " " << r << " " << c << " ";
    if (x >= 7) {
        cout << "RICHARD";
        return;
    }
    if (min(r, c) * 2 + 1 <= x) {
        cout << "RICHARD";
        return;
    }
    if (r * c % x != 0) {
        cout << "RICHARD";
        return;
    }
    if (min(r, c) == 2 && x == 4) {
        cout << "RICHARD";
        return;
    }
    if (min(r, c) == 3 && (x == 5 || x == 6)) {
        cout << "RICHARD";
        return;
    }
    cout << "GABRIEL";
}

int main() {
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }
}
