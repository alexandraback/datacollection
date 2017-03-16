#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int n;
double a[10000];
double b[10000];
int was[10000];
int go(int l1, int r1, int l2, int r2) {
    if (r1 - l1 + 1 == 0) {
        return 0;
    }
    if (a[r1] < b[r2] || a[l1] < b[l2]) {
        return go(l1 + 1, r1, l2, r2 - 1);
    }
    if (a[l1] > b[r2]) {
        return r1 - l1 + 1;
    }
    return 1 + go(l1 + 1, r1, l2 + 1, r2);
}
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans2 = 0;
        for (int it = 0; it < 2; it++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                was[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                int wh = -1;
                for (int j = 0; j < n; j++) if (b[j] > a[i] && was[j] == 0) {
                    wh = j;
                    break;
                }
                if (wh == -1) {
                    cur++;
                    for (int j = 0; j < n; j++) if (b[j] < a[i] && was[j] == 0) {
                        wh = j;
                        break;
                    }
                }
                was[wh] = 1;
            }
            ans2 = max(ans2, cur);
            reverse(a, a + n);
        }
        int ans1 = go(0, n - 1, 0, n - 1);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
