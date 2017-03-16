#include <iostream>
#include <vector>

using namespace std;

string solve() {
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= ans[0]) {
            ans = s[i] + ans;
        } else {
            ans += s[i];
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}