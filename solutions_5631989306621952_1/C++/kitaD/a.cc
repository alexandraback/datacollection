#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    for(int tt = 1; tt <= T; ++tt) {
        string s;
        cin >> s;
        string ans;
        for(int i = 0; i < s.size(); ++i) {
            string s1 = s[i] + ans;
            string s2 = ans + s[i];
            ans = max(s1, s2);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
