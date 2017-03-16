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
        for (int i = 0; i < s.size(); i++) {
            bool good = false;
            int cnt = 0;
            for (int j = i; j < s.size(); j++) {
                if (is(s[j])) {
                    cnt = 0;
                } else {
                    cnt++;
                }
                if (cnt >= n) {
                    good = true;
                }
                if (good || cnt >= n) {
                    ans++;
                }
            }
        }
        cout << "Case #" << ca << ": " << ans << "\n";
    }
    return 0;
}
