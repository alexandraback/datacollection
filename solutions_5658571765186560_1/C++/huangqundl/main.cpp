#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve() {
    int X, R, C;
    cin >> X >> R >> C;
    if (R > C) {
        int tmp = R;
        R = C;
        C = tmp;
    }

    if (R*C % X > 0) {
        cout << "RICHARD" << endl;
        return;
    }
    if (X >= 7) {
        cout << "RICHARD" << endl;
        return;
    }
    if (X <= R) {
        cout << "GABRIEL" << endl;
        return;
    }
    if (X > C) {
        cout << "RICHARD" << endl;
        return;
    }

    // R<X<=C && C*R % X ==0, 1<X<=6
    if (X==6) {
        if (R==5) {
            cout << "GABRIEL" << endl;
            return;
        }
        if (R==4) {
            cout << "RICHARD" << endl;
            return;
        }
        if (R==3) {
            cout << "RICHARD" << endl;
            return;
        }
        else {
            cout << "RICHARD" << endl;
            return;
        }
    }
    if (X==5) {
        // we must have C % X == 0
        if (R<=2) {
            cout << "RICHARD" << endl;
            return;
        }
        if (R==3 && C==5) {
            cout << "RICHARD" << endl;
            return;
        }
        else {
            cout << "GABRIEL" << endl;
            return;
        }
    }
    if (X==4) {
        if (R==1) {
            cout << "RICHARD" << endl;
            return;
        }
        if (R==2) {
            cout << "RICHARD" << endl;
            return;
        }
        if (R==3) {
            cout << "GABRIEL" << endl;
            return;
        }
    }
    if (X==3) {
        // we must have C % X == 0
        if (R==1) {
            cout << "RICHARD" << endl;
            return;
        }
        else {
            cout << "GABRIEL" << endl;
            return;
        }
    }
    if (X==2) {
        cout << "GABRIEL" << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
