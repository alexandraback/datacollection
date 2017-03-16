#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int T;
int n;
int ans = 2e9, ansa = 2e9, ansb = 2e9;
char as[9999], bs[9999];
char s[9999];
char t[9999];

void brute(int idx) {
    if (idx == 2 * n) {
        int x = atoi(s);
        int y = atoi(t);
        int xy = abs(x - y);
        if (xy < ans || xy == ans && (x < ansa || x == ansa && y < ansb)) {
            ans = xy;
            ansa = x;
            ansb = y;
            strcpy(as, s);
            strcpy(bs, t);
        }
        return;
    }

    if (idx < n) {
        if (s[idx] == '?') {
            for (int i = 0; i <= 9; ++i) {
                s[idx] = i + '0';
                brute(idx + 1);
            }
            s[idx] = '?';
        } else brute(idx + 1);
    } else {
        if (t[idx - n] == '?') {
            for (int i = 0; i <= 9; ++i) {
                t[idx - n] = i + '0';
                brute(idx + 1);
            }
            t[idx - n] = '?';
        } else brute(idx + 1);
    }
}

int main()
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);

    cin >> T;
    for (int ttt = 1; ttt <= T; ++ttt) {
        cin >> s >> t;
        n = strlen(s);
        ans = ansa = ansb = 2e9;
        brute(0);

        cout << "Case #" << ttt << ": " << as << " " << bs << "\n";
    }

    return 0;
}
