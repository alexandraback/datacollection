
#include <iostream>
#include <string>

using namespace std;

string solve(string s) {
    string r = "";
    for (int i = 0; i < s.size(); i++) {
        bool left = true;
        for (int j = 0; j <= r.size(); j++) {
            char c1 = (j == 0 ? s[i] : r[j - 1]);
            char c2 = (j == r.size() ? s[i] : r[j]);
            if (c1 > c2) {
                left = true;
                break;
            }
            if (c1 < c2) {
                left = false;
                break;
            }
        }
        if (left)
            r = s[i] + r;
        else
            r = r + s[i];
    }
    return r;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }
}
