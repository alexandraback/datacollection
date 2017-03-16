#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int T;
int n;
ll ans, ansa, ansb;
char as[9999], bs[9999];
char s[9999];
char t[9999];

ll numtoll(char* ss) {
    ll x = 0;
    for (int i = 0; ss[i]; ++i)
        x = x * 10 + ss[i] - 48;
    return x;
}

void brute(int i, int mode) {
    if (i == n) {
        ll x = numtoll(s);
        ll y = numtoll(t);
        ll xy = (x <= y ? y - x : x - y);
        if (xy < ans || xy == ans && (x < ansa || x == ansa && y < ansb)) {
            ans = xy;
            ansa = x;
            ansb = y;
            strcpy(as, s);
            strcpy(bs, t);
        }
        return;
    }

    if (s[i] != '?' && t[i] != '?') {
        if (mode != 0)
            brute(i + 1, mode);
        else if (s[i] < t[i])
            brute(i + 1, -1);
        else if (s[i] > t[i])
            brute(i + 1, 1);
        else
            brute(i + 1, 0);
        return;
    }

    if (mode == -1) { /// x <  y
        int restore_s = 0, restore_t = 0;
        if (s[i] == '?') {
            restore_s = 1;
            s[i] = '9';
        }
        if (t[i] == '?') {
            restore_t = 1;
            t[i] = '0';
        }
        brute(i + 1, mode);
        if (restore_s) s[i] = '?';
        if (restore_t) t[i] = '?';
    } else if (mode == 0) { /// ==
        if (s[i] == '?' && t[i] == '?') {
            s[i] = '0';
            t[i] = '0';
            brute(i + 1, 0);
            s[i] = '0';
            t[i] = '1';
            brute(i + 1, -1);
            s[i] = '1';
            t[i] = '0';
            brute(i + 1, 1);
            s[i] = '?';
            t[i] = '?';
        } else if (s[i] == '?') {
            s[i] = t[i];
            brute(i + 1, 0);
            if (t[i] >= '1') {
                s[i] = t[i] - 1;
                brute(i + 1, -1);
            }
            if (t[i] <= '8') {
                s[i] = t[i] + 1;
                brute(i + 1, 1);
            }
            s[i] = '?';
        } else {
            t[i] = s[i];
            brute(i + 1, 0);
            if (s[i] >= '1') {
                t[i] = s[i] - 1;
                brute(i + 1, 1);
            }
            if (s[i] <= '8') {
                t[i] = s[i] + 1;
                brute(i + 1, -1);
            }
            t[i] = '?';
        }
    } else if (mode == 1) { /// x > y
        int restore_s = 0, restore_t = 0;
        if (s[i] == '?') {
            restore_s = 1;
            s[i] = '0';
        }
        if (t[i] == '?') {
            restore_t = 1;
            t[i] = '9';
        }
        brute(i + 1, mode);
        if (restore_s) s[i] = '?';
        if (restore_t) t[i] = '?';
    }
}

int main()
{
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    cin >> T;
    for (int ttt = 1; ttt <= T; ++ttt) {
        cin >> s >> t;
        n = strlen(s);
        ans = ansa = ansb = 9e18;
        brute(0, 0);

        cout << "Case #" << ttt << ": " << as << " " << bs << "\n";
    }

    return 0;
}
