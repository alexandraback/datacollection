#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

ll t, n, k, c, s;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("D-large.in", "r",  stdin));
    freopen("D-large.out", "w", stdout);
    cin >> t;
    forn (i, t) {
        cin >> k >> c >> s;
        cout << "Case #" << i + 1 << ": ";
        if (c == 1) {
            if (s < k) {
                cout << "IMPOSSIBLE\n";
                continue;
            }
            forn (i, s) cout << i + 1 << " ";
            cout << "\n";
            continue;
        }
        if (s < (k + 1) / 2) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        ll nu = k, p = 1, j = 0;
        forn (i, c - 1) p *= k;
        forn (i, (k + 1) / 2) {
            cout << nu + j << " ";
            nu--;
            j += p;
        }
        cout << "\n";
    }

    return 0;
}

