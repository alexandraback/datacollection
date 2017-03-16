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

string kb, d, dd;
int a[100];

int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
        int k, l, s, i, j;
        double zn = 1, ch = 1, mx = 0;
        cin >> k >> l >> s;
        cin >> kb >> d;
        if(l > s) {
            printf("Case #%d: 0\n", tt);
            continue;
        }
        for(i = 1; i <= s; i++) {
            zn *= k;
            if(i <= s - d.size())
                ch *= k;
        }
//        cout << "chfirst=" << ch << "\n";
        memset(a, 0, sizeof(a));
        for(auto x: kb)
            a[x]++;
        for(auto x: d)
            ch *= a[x];

//        cout << "chsecond=" << ch << "\n";
        ch *= (s - d.size() + 1);
//        cout << "chlast=" << ch << "\n";
        dd = "";
        for(i = 0; dd.size() < s && ch != 0; i++) {
//            cout << i << ' ' << dd << "\n";
            if(i >= dd.size()) {
                dd += d;
                if(dd.size() <= s)
                    mx++;
            } else {
                bool bb = 1;
                for(j = 0; j + i < dd.size(); j++)
                    if(dd[i + j] != d[j]) {
                        bb = 0;
                        break;
                    }
                if(bb == 0)
                    continue;
                for(j = dd.size() - i; j < d.size(); j++)
                    dd += d[j];
                if(dd.size() <= s)
                    mx++;
            }
        }
//        cout << mx << ' ' << ch << ' ' << zn << '\n';
        printf("Case #%d: %.10f\n", tt, (1. * mx - (1. * ch) / zn));
    }
    return 0;
}
