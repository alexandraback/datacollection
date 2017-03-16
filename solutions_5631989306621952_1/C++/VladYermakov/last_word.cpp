#include <bits/stdc++.h>

using namespace std;

main () {

    freopen ("a-large.in", "r", stdin);
    freopen ("a.out", "w", stdout);

    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        cout << "Case #" << num <<  ": ";
        string s;
        cin >> s;
        string t = "";
        t += s[0];
        for (int i = 1; i < s.length (); ++i) {
            if (s[i] >= t[0]) t = s[i] + t;
            else t += s[i];
        }
        cout << t << "\n";
    }
}
