#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int ntc;
    cin >> ntc;
    for (int itc = 1; itc <= ntc; ++itc) {
        int n; string s;
        cin >> n >> s;
        int ans = 0, cur = 0;
        for (int i = 0; i <= n; ++i) {
            if (cur < i) {
                ans += i-cur;
                cur = i;
            }
            cur += s[i]-'0';
        }
        cout << "Case #" << itc << ": " << ans << endl;
    }
}
