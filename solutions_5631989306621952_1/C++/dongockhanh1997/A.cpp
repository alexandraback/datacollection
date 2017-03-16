#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        string s, res; cin >> s;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] + res < res + s[i]) res += s[i];
            else res = s[i] + res;
        }
        cout << "Case #" << tc << ": " << res << '\n';
    }
    return 0;
}
