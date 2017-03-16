#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int f0[N], f1[N];

int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        string s;
        cin >> s;
        if (s[0] == '+') {
            f0[0] = 0; f1[0] = 1;
        }
        else {
            f0[0] = 1; f1[0] = 0;
        }
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                f0[i] = f0[i-1];
                f1[i] = f1[i-1];
            }
            else {
                if (s[i] == '+') {
                    f0[i] = min(f0[i-1], f1[i-1]+2);
                    f1[i] = min(f0[i-1]+1, f1[i-1]+2);
                }
                else {
                    f1[i] = min(f1[i-1], f0[i-1]+2);
                    f0[i] = min(f1[i-1]+1, f0[i-1]+2);
                }
            }
        }
        cout << "Case #" << nt << ": " << f0[s.length()-1] << '\n';
    }
    return 0;
}
