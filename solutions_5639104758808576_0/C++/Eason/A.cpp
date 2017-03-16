#include <iostream>
#include <string>
using namespace std;

int T, S;
string s;

void solve() {
    int cnt = (s[0] - '0'), res = 0;
    for (int i = 1; i <= S; ++i) {
        if (s[i] != '0' && cnt < i) {
            res += (i - cnt);
            cnt += res;
        }
        cnt += (s[i] - '0');
    }
    cout << res << endl;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> S >> s;
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
