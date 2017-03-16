#include <iostream>
#include <string>
using namespace std;

string solve(const string & s) {
    string ans;
    for (char c : s) {
        if (ans.empty() || ans[0]>c) {
            ans += c;
        } else {
            ans = c+ans;
        }
    }
    return ans;
}

int main() {
    int T; cin >> T;
    for (int i=1; i<=T; ++i) {
        string s; cin >> s;
        string ans = solve(s);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
