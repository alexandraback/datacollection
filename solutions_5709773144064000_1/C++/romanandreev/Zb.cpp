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

int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    assert(freopen(problem_name".in","rt",stdin));
    #endif
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);
        double curT = 0;
        double curS = 2;
        double ans = 1e100;
        while (curT < ans) {
            ans = min(ans, curT + X / curS);
            curT += C / curS;
            curS += F;
        }
        printf("%.18lf\n", ans);
    }
    return 0;
}
