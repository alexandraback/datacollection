#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int k, n;
int key[1000];
int type[1000];
vi loot[1000];
int dp[1<<21];
int dost[1<<21];
vi g[1<<21];
vi g1[1<<21];


int num[1000];
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ti++) {
        printf("Case #%d: ", ti + 1);
        scanf("%d %d", &k, &n);
        vi vx;
        for (int i = 0; i < k; i++) {
            scanf("%d", &key[i]);            
        }
        for (int i = 0; i < n; i++) {
            int k0;
            scanf("%d %d", &type[i], &k0);
            vx.pb(type[i]);
            loot[i].clear();
            for (int j = 0; j < k0; j++) {
                int x;
                scanf("%d", &x);
                loot[i].pb(x);
            }
        }
        sort(all(vx));
        for (int i = 0; i < k; i++) {
            int ff = lower_bound(all(vx), key[i]) - vx.begin();
            if (ff != n && vx[ff] != key[i]) {
                ff = n;
            }
            key[i] = ff;
        }
        for (int i = 0; i < n; i++) {
            int ff = lower_bound(all(vx), type[i]) - vx.begin();
            if (ff != n && vx[ff] != type[i]) {
                ff = n;
            }
            type[i] = ff;
            for (int j = 0; j < sz(loot[i]); j++) {
                int ff = lower_bound(all(vx), loot[i][j]) - vx.begin();
                if (ff != n && vx[ff] != loot[i][j]) {
                    ff = n;
                }
                loot[i][j] = ff;
            }
        }


        for (int i = 0; i < (1 << n); i++) {
            dp[i] = 0;
            g[i].clear();
            g1[i].clear();
            dost[i] = 0;
        }
        dp[0] = 1;
        for (int i = 0; i < (1 << n); i++) if (dp[i]) {
            for (int j = 0; j < sz(vx); j++) {
                num[j] = 0;
            }
            for (int j = 0; j < k; j++) {
                num[key[j]]++;
            }
            for (int j = 0; j < n; j++) if ((i >> j) & 1) {
                num[type[j]]--;
                for (int f = 0; f < sz(loot[j]); f++) {
                    num[loot[j][f]]++;
                }
            }
            for (int j = 0; j < n; j++) if (num[type[j]] > 0 && ((i >> j) & 1) == 0) {
                dp[i | (1 << j)] = 1;
                g[i | (1 << j)].pb(i);
                g1[i].pb(j);
            }
        }
        if (dp[(1 << n) - 1] == 1) {
            dost[(1 << n) - 1] = 1;
        }
        for (int i = (1 << n) - 1; i >= 0; i--) if (dost[i]) {
            for (int j = 0; j < sz(g[i]); j++) {
                dost[g[i][j]] = 1;
            }
        }
        if (dp[(1 << n) - 1]) {
            int tk = 0;
            for (int i = 0; i < n; i++) {
                bool was = false;
                for (int j1 = 0; j1 < sz(g1[tk]); j1++) {
                    int j = g1[tk][j1];
                    if (((tk >> j) & 1) == 0 && dost[tk | (1 << j)]) {
                        tk = tk | (1 << j);
                        was = true;
                        printf("%d%c", j + 1, " \n"[i + 1 == n]);
                        break;
                    }
                }
                assert(was);
            }
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    #ifdef home                    
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 