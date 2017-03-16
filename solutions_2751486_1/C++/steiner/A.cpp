#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

bool vowel(char ch) {
    if (ch == 'a')
        return true;
    if (ch == 'e')
        return true;
    if (ch == 'i')
        return true;
    if (ch == 'o')
        return true;
    if (ch == 'u')
        return true;
    return false;
}

void solve() {
    string s;
    int64 n;
    cin >> s >> n;
    int64 m = sz(s);
    vector<int64> a(m, 0);
    for (int64 i = 0; i < m; ++i) {
        if (vowel(s[i]))
            continue;
        a[i] = 1;
        if (i > 0)
            a[i] += a[i - 1];  
    }
    vector<int64> prev(m, -1);
    for (int64 i = 1; i < m; ++i) {
        if (a[i - 1] >= n)
            prev[i] = i - 1;
        else
            prev[i] = prev[i - 1];
    }
    vector<int64> dp(m, 0);
    int64 ans = 0;
    for (int64 i = 0; i < m; ++i) {
        if (i > 0)
            dp[i] = dp[i - 1];
        if (a[i] >= n)
            if (prev[i] == -1)
                dp[i] += (i - n + 2);
            else
                dp[i] += (i - prev[i]);
        ans += dp[i];
    }
    cout << ans << endl;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
