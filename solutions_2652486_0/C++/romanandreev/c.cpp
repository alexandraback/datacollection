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
int r, n, m, k;
ll a[100];
int b[100];
set<ll> S;
set<ll> S1;
string ans;
void bct(int t) {
    if (t == n) {
        S1.clear();
        for (int i = 0; i < (1 << n); i++) {
            ll mp = 1;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    mp *= b[j];
                }
            }
            S1.insert(mp);
        }
        for (set<ll>::iterator it = S.begin(); it != S.end(); it++) {
            if (S1.find(*it) == S1.end()) {
                return;
            }
        }
        ans = "";
        for (int i = 0; i < n; i++) {
            ans += '0' + b[i];
        }
        return;
    }
    for (int i = 2; i <= m; i++) {
        b[t] = i;
        bct(t + 1);
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d", &k);
    printf("Case #1:\n");
    scanf("%d %d %d %d", &r, &n, &m, &k);
    for (int ti = 0; ti < r; ti++) {
        S.clear();
        for (int i = 0; i < k; i++) {
            scanf("%I64d", &a[i]);
            S.insert(a[i]);
        }
        ans = "";
        for (int i = 0; i < n; i++) {
            ans += "2";
        } 
        bct(0);
        printf("%s\n", ans.c_str());
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 