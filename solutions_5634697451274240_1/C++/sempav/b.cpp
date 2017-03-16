#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; ++testCase) {
        int ans = 0;
        string s;
        cin >> s;
        s += "+";
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                ans++;
            }
        }
        cout << "Case #" << testCase << ": " << ans << endl;
    }
    return 0;
}
