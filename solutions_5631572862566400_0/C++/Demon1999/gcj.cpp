#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int t, n, ak, fr[30000], mh[30000], h[30000], use[30000], on_cycle[30000], pp[30000], ans = 0, pr[30000], kp;
vector<pair<int, int> > nu;

pair<int, int> dfs(int i, int p) {
    pr[i] = p;
    if (use[i] == 2) {
        re {on_cycle[i], h[i]};
    }
    if (use[i] == 1) {
        int nu1 = i, k = 0;
        while (true) {
            k++;
            mh[nu1] = 0;
            h[nu1] = 0;
            on_cycle[nu1] = nu1;
            nu1 = pr[nu1];
            if (nu1 == i) break;
        }
        if (k == 2) {
            nu.push_back(mp(i, pr[i]));
            kp += 2;
        }
        ans = max(ans, k);
        re {i, 0};
    }
    use[i] = 1;
    pii j = dfs(fr[i], i);
    int k = 0;
    if (on_cycle[i] == -1) {
        on_cycle[i] = j.fi;
        h[i] = j.se + 1;
        mh[j.fi] = max(mh[j.fi], j.se + 1);
        k = j.se + 1;
    }
    use[i] = 2;
    re {on_cycle[i], h[i]};
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("C-small-attempt1.in", "r",  stdin));
    freopen("C-small-attempt1.out", "w",  stdout);
    cin >> t;
    forn (i, t) {
        cin >> n;
        forn (i, n) {
            mh[i] = -1;
            h[i] = -1;
            on_cycle[i] = -1;
            use[i] = 0;
            pr[i] = -1;
            cin >> fr[i];
            fr[i]--;
        }
        nu.resize(0);
        ans = 0; kp = 0;
        forn (i, n) {
            if (!use[i]) {
                dfs(i, -1);
            }
        }
        forn (i, sz(nu)) {
            kp += mh[nu[i].fi];
            kp += mh[nu[i].se];
        }
        cout << "Case #" << i + 1 << ": " << max(ans, kp) << "\n";
    }
    return 0;
}

