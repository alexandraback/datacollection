#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef long long LL;

#define N (1<<20)
double a[N], p[N];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        int m, n;
        scanf("%d%d", &m, &n);
        forn(i, m) scanf("%lf", &a[i]);
        p[0] = 1.;
        forn(i, m) p[i+1] = p[i]*a[i];
        double ans = n + 2.;
        forn(d, m+1) {
            //printf("%d %.3lf  %d %.3lf    %.3lf\n", n-m+d+d+1, p[m-d], 1+d+n+n-m+1, 1.-p[m-d], d + p[m-d]*(n-m+d+1) + (1.-p[m-d])*(d+d+n-m+1+n+1));
            ans = min(ans, d + p[m-d]*(n-m+d+1) + (1.-p[m-d])*(d+n-m+1+n+1));
        }
        printf("Case #%d: %.20lf\n", _+1, ans);
    }
    return 0;
}

