#include <iostream>
#include <string>

using namespace std;

inline bool is(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        string s;
        int n;
        cin >> s >> n;
        int ans = 0;
        int j = 0;
        int len = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (is(s[i])) {
                len = 0;
            } else {
                len++;
            }
            if (len >= n) {
                j = i - n + 2;
            }
            ans += j;
        }
        cout << "Case #" << ca << ": " << ans << "\n";
    }
    return 0;
}
