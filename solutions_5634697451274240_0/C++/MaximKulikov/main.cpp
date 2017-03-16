#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

#define PROBLEM "B-small-attempt0"

int solve(string s) {
    int ret = 0, n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            ret++;
    }
    if (s[n-1] == '-') ret++;
    return ret;
}

int main()
{
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << solve(s) << endl;
    }

    return 0;
}
