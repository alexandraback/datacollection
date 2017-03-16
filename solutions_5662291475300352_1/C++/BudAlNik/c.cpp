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
const long double eps = 1e-9;

int t;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cerr << i << endl;
        int n;
        cin >> n;
        vector <pair <long double, int> > v;
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
        set <pair <long double, pii > > s;
        for (int j = 0; j < szof(v); ++j) {
            s.insert(mapa(v[j].ff, mapa(v[j].ss, -1)));
        }
        int now = c;
        int del = 0;
        int ans = c;
        int plu = 0;
        while (true) {
            if (plu >= c) {
                break;
            }
            pair <long double, pii > p = *s.begin();
            s.erase(s.begin());
            now += p.ss.ss;
            if (p.ss.ss == 1) {
                ++plu;
            }
            s.insert(mapa(p.ff + lt[p.ss.ff], mapa(p.ss.ff, 1)));
            if (s.begin() -> ff > p.ff + eps) {
                ans = min(ans, now);
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

    return 0;
}