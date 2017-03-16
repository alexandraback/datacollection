#include <bits/stdc++.h>
using namespace std;

int main() {
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < (int) s.size(); ++i)
            if (s[i] == '-' && (i == 0 || s[i - 1] == '+'))
                ++cnt;
        int ans = 2 * cnt;
        if (s[0] == '-') --ans;
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}
