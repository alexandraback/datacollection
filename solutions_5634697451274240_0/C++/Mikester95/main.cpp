#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

int solve() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[i-1]) {
            ++ans;
        }
    }

    if (s.back() == '-') {
        ++ans;
    }

    return ans;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test;
    cin >> test;
    for (int k = 1; k <= test; ++k) {
        int ans = solve();
        cout << "Case #" << k << ": " << ans << "\n";
    }
}
