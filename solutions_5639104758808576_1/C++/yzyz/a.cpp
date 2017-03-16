#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
string s;

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n >> s;
        int ans = 0, ct = 0;
        for (int i = 0; i <= n; i++) {
            if (ct < i) {
                ans += i - ct;
                ct = i;
            }
            ct += s[i] - '0';
        }
        cout << "Case #" << TC << ": ";
        cout << ans << '\n';
    }
}
