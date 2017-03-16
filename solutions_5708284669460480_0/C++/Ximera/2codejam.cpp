#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

string b, d;
int st, kl, mx;

void go(int k, string s) {
    if(k == 0) {
//        cout << s << ' ' << d << '\n';
        int kol = 0;
        for(int i = 0; i + d.size() <= s.size(); i++) {
            bool l = true;
            for(int j = 0; j < d.size(); j++)
                if(s[i + j] != d[j]) {
                    l = false;
                    break;
                }
            if(l) kol++;
        }
//        cout << "\t" << kol << "\n";
        mx = max(mx, kol);
        st++;
        kl += kol;
    } else {
        for(auto x: b) {
            go(k - 1, s + x);
        }
    }
}

int main() {
    inp("input.txt");
    out("output.txt");
    int t, i, tt;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
        int k, l, s;
        cin >> k >> l >> s;
        cin >> b >> d;
        mx = kl = st = 0;
        go(s, "");
//        cout << mx << ' ' << kl << ' ' << st << "\n";
        printf("Case #%d: %.10f\n", tt, (st == 0 ? 0: (1. * mx - (1. * kl) / st)));
    }
}
