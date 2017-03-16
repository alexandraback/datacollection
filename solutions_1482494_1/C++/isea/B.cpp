/*
 * by purple
 * at 12-04-28 9:58:25
 */

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define rep(i,n) for(int i=0;i<(n);++i)
#define repf(i,a,b) for(int i=(a);i<=(b);++i)

int n;
pair<int, int> p[1024];
bool f[1024];

int main() {
    freopen ("B.out", "w", stdout);
    
    int t, Case = 1;
    for (scanf ("%d", &t); t; --t) {
        scanf ("%d", &n);
        int ans = 0;
        bool can = true;
        //set<pair<int, int> > all;
        rep (i, n) {
            scanf ("%d%d", &p[i].second, &p[i].first);
        }
        sort (p, p + n);
        rep (i, n) {
            //all.insert (pair<int, int> (p[i].second, i));
            f[i] = false;
        }
        int now = 0;
        rep (i, n) {
            int need = p[i].first - now;
            //out(need);
            while (need > 0) {
                bool found = false;
                for (int j = n - 1; j >= i; --j) {
                    if (!f[j] && p[j].second <= now) {
                        now++; ans++; need--;
                        f[j] = true; found = true;
                        break;
                    }
                }
                if (!found) {
                    break;
                }
            }
            //out(need);
            if (need > 0) {
                can = false;
                break;
            }
            if (!f[i]) now += 2;
            else now += 1;
            ++ans;
        }
        printf ("Case #%d: ", Case++);
        if (!can) {
            printf ("Too Bad\n");
        } else {
            printf ("%d\n", ans);
        }
    }
    return 0;
}

