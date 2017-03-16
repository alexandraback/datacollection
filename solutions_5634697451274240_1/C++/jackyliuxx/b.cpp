#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int tsk = 1; tsk <= T; tsk++) {
        string s;
        cin >> s;
        s += '+';
        int ans = 0;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                ans++;
            }
        }
        cout << "Case #" << tsk << ": " << ans << endl;
    }
}
