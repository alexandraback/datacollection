#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void Solve(int test_num) {
    cout << "Case #" << test_num << ": ";
    string s;
    cin >> s;
    s += '+';
    int ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] != s[i - 1]) ++ans;
    }
    cout << ans << "\n";
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i) Solve(i);
}
