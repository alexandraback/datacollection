#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

string solve() {
    string s, t;
    cin >> s >> t;
    int os = s.size(), ot = t.size();
    while (s.size() < 3) {
        s = "0" + s;
    }
    while (t.size() < 3) {
        t = "0" + t;
    }
    int r = 1001;
    string sl, sr;
    for (int i = 0; i < 1000; ++i) {
        int d1 = i / 100;
        int d2 = i / 10 % 10;
        int d3 = i % 10;
        if ( (s[0] == '?' || (s[0] - '0') == d1) && (s[1] == '?' || (s[1] - '0') == d2) && (s[2] == '?' || (s[2] - '0') == d3) ) {
            for (int j = 0; j < 1000; ++j) {
                d1 = j / 100;
                d2 = j / 10 % 10;
                d3 = j % 10;
                if ( (t[0] == '?' || (t[0] - '0') == d1) && (t[1] == '?' || (t[1] - '0') == d2) && (t[2] == '?' || (t[2] - '0') == d3) && r > abs(i - j)) {
                    r = min(r, abs(i - j));
                    sl = "999";
                    sl[0] = '0' + (i / 100);
                    sl[1] = '0' + (i / 10 % 10);
                    sl[2] = '0' + (i % 10);
                    sr = "999";
                    sr[0] = '0' + (j / 100);
                    sr[1] = '0' + (j / 10 % 10);
                    sr[2] = '0' + (j % 10);
                }
            }
        }
    }
    sl = sl.substr(3 - os, os);
    sr = sr.substr(3 - ot, ot);
    return sl + " " + sr;
}

int main() {
#ifdef ALEXEY
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(7) << std::fixed;
#endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}
