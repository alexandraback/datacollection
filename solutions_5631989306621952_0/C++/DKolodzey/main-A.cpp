#include <iostream>
#include <vector>

using namespace std;

bool containsLettersGreaterOrEqualToFirst(const string& s) {
    bool ans = false;
    for (int i = 1; i < s.length(); ++i) {
        ans |= s[i] >= s[0];
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        string s;
        cin >> s;
        /*
        if (!containsLettersGreaterOrEqualToFirst(s)) {
            cout << s << endl;
            continue;
        }
        */
        vector<bool> to_start(s.length(), false);
        int last_entry = s.length();
        for (char ch = 'Z'; ch >= s[0]; --ch) {
            for (int i = last_entry - 1; i > 0; --i) {
                    if (s[i] == ch) {
                        last_entry = i;
                        to_start[i] = true;
                    }
                }
            }
        string ans = string(1, s[0]);
        for (int i = 1; i < s.length(); ++i){
            if (to_start[i]){
                ans = s[i] + ans;
            } else {
                ans = ans + s[i];
            }
        }
        
        cout << ans << endl;
        /*
        cout << s << endl;
        for (int i = 0; i < s.length(); ++i)
            cout << to_start[i];
        cout << endl;
        */
        
    }
    return 0;
}