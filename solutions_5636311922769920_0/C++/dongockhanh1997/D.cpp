#include <bits/stdc++.h>
using namespace std;

int main() {
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        cout << "Case #" << tc << ":";
        int k, c, s; cin >> k >> c >> s;
        for (int i = 1; i <= k; ++i) cout << ' ' << i;
        cout << '\n';
    }
    return 0;
}
