#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
using namespace std;
void solve() {
    string s; cin >> s;
    auto flip = [&](int r) {
        string t = s;
        repeat (i,r) t[i] = s[r-i-1] == '+' ? '-' : '+';
        s = t;
    };
    int ans = 0;
    while (s.find('-') != string::npos) {
        if (s[0] == '+') {
            flip(s.find('-'));
        } else {
            flip(s.rfind('-') + 1);
        }
        ++ ans;
    }
    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
