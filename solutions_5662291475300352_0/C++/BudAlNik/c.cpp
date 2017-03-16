#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;

int t;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector <pair <double, int> > v;
        vector <int> lt;
        int c = 0;
        for (int j = 0; j < n; ++j) {
            int d, h, m;
            cin >> d >> h >> m;
            for (int k = 0; k < h; ++k) {
                v.puba(mapa((360 - d) / 360.0 * m, c));
                lt.puba(m);
                ++m;
                ++c;
            }
        }
        set <pair <double, pii > > s;
        for (int j = 0; j < szof(v); ++j) {
            s.insert(mapa(v[j].ff, mapa(v[j].ss, -1)));
        }
        int now = c;
        int del = 0;
        int ans = n;
        while (true) {
            if (del == c && now >= c) {
                break;
            }
            pair <double, pii > p = *s.begin();
            s.erase(s.begin());
            now += p.ss.ss;
            if (p.ss.ss == -1) {
                ++del;
            }
            s.insert(mapa(p.ff + lt[p.ss.ff], mapa(p.ss.ff, 1)));
            if (s.begin() -> ff != p.ff) {
                ans = min(ans, now);
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

    return 0;
}