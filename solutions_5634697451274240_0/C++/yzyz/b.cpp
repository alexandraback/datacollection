#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

string s;

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> s;

        s += '+';
        int n = s.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1])
                ans++;
        }

        cout << "Case #" << TC << ": ";
        cout << ans << '\n';
    }
}
