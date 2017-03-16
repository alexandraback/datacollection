#include <bits/stdc++.h>

using namespace std;

int f[100][2];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("RevengePancakes.out", "w", stdout);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        //cout << s << endl;
        int n = s.length();
        if (s[0] == '+') {
            f[0][0] = 1;
            f[0][1] = 0;
        } else {
            f[0][0] = 0;
            f[0][1] = 1;
        }

        for (int j = 1; j < n; j++)
            if (s[j] == '+') {
                f[j][0] = f[j-1][1] + 1;
                f[j][1] = f[j-1][1];
            } else {
                f[j][0] = f[j-1][0];
                f[j][1] = f[j-1][0] + 1;
            }

        cout << "Case #" << i << ": " << f[n-1][1] << endl;
    }
}
