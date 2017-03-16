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

int a[1024], b[1024];
int c[12];
int f[1<<22];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        memset(f, 0x3C, sizeof f);
        int n;
        scanf("%d", &n);
        forn(i, n) scanf("%d%d", &a[i], &b[i]);
        
        int m = 1;
        forn(i, n) m *= 3;
        f[0] = 0;
        forn(mask, m) {
            int x = mask;
            int k = 0;
            forn(___,n) c[k++] = x % 3, x /= 3;
            int have = 0;
            forn(i, n) have += c[i];
//printf("%d %d %d   %d%d%d%d\n", mask, f[mask], have, c[0], c[1], c[2], c[3]);
            forn(i, n) {
                if (c[i] < 1 && have >= a[i]) {
                    int u = 0;
                    c[i] = 1;
                    forn(j, n) u = u*3 + c[n-1-j];
                    c[i] = 0;
                    f[u] = min(f[u], f[mask] + 1);
                }
                if (c[i] < 2 && have >= b[i]) {
                    int u = 0, tmp = c[i];
                    c[i] = 2;
                    forn(j, n) u = u*3 + c[n-1-j];
                    c[i] = tmp;
                    f[u] = min(f[u], f[mask] + 1);
                }
            }
        }
        printf("Case #%d: ", _+1);
        if (f[m-1] == 0x3C3C3C3C) printf("Too Bad\n");
        else printf("%d\n", f[m-1]);
        
    }
    return 0;
}

