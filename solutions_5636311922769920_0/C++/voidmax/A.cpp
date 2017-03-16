//#include "grader.h"
#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

typedef long long base;

string FileName = "input";

int t, n, m, c;

base TakeCoor(base n, base k, base c) {
    if (c == 1) return k;
    return TakeCoor(n, n * k, c - 1);
}

int main() {
    //files(FileName);
    ios::sync_with_stdio(false);
    cin >> t;
    For(i, 0, t) {
        cout << "Case #" << i + 1 << ": ";
        cin >> n >> m >> c;
        if (m == 1) {
            if (c < n) {
                cout << "IMPOSSIBLE" << endl;
            } else {
                For(j, 0, n) cout << j + 1 << ' '; cout << endl;
            }
        } else {
            vector <base> check;
            base L = 0, R = n - 1;
            while (L <= R) {
                check.pb(TakeCoor(n, L, m) + R);
                ++L; --R;
            }
            if (check.size() > c) {
                cout << "IMPOSSIBLE" << endl;
            } else {
                for(base j: check) cout << j + 1 << ' '; cout << endl;
            }
        }
    }
}
