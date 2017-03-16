#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) ans++;
    }
    if (s.back() != '+') ans++;
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int ans = 0;
        ans = solve();
        cout << "Case #" << testcase << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
