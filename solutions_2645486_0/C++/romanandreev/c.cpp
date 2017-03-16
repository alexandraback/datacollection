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
int ans = 0;
int cur = 0;
int E, R, n;
int v[100];
void bct(int k, int e) {
    if (k == n) {
        ans = max(ans, cur);
        return;
    }
    for (int i = 0; i <= e; i++) {
        bct(k + 1, min(e - i + R, E));
        cur += v[k];
    }
    cur -= (e + 1) * v[k];
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ti++) {
        scanf("%d %d %d", &E, &R, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        ans = 0;
        cur = 0;
        bct(0, E);
        printf("Case #%d: %d\n", ti + 1, ans);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
 