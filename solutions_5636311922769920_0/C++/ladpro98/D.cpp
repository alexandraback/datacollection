#include <bits/stdc++.h>

using namespace std;

int k, c, s;

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int ntest; cin >> ntest;
    for (int it = 1; it <= ntest; ++it) {
        cin >> k >> c >> s;
        cout << "Case #" << it << ": ";
        for (int i = 1; i <= s; ++i) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
