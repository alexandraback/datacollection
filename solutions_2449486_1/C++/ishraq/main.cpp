// Ishraq Huda
// lawn
// Sat, Apr 13, 2013 10:51:00 AM

#include <cstdio>
#include <cctype>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for(int i=(a);i<(b);i++)
#define FR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define fi(a) FO(i,0,a)
#define fj(a) FO(j,0,a)
#define fk(a) FO(k,0,a)
#define all(c) (c).begin(), (c).end()
#define fit(c,i) \
    for (typeof((c).begin()) i=(c).begin(); i != (c).end(); i++)
#define sd(n) scanf(" %d ", &(n))

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main() {
#ifndef DEBUG
    // freopen("lawn.in", "r", stdin);
    // freopen("lawn.out", "w", stdout);
#endif

    int T;
    sd(T);
    FO(Z,1,T+1) {
        int n, m;
        sd(n); sd(m);
        int grid[105][105];
        int curr[105][105];
        fi(n) {
            fj(m) {
                curr[i][j] = 100;
                sd(grid[i][j]);
            }
        }
        fi(n) {
            int to_cut = 0;
            fj(m) {
                to_cut = max(to_cut, grid[i][j]);
            }
            fj(m) {
                curr[i][j] = min(to_cut, curr[i][j]);
            }
        }
        fj(m) {
            int to_cut = 0;
            fi(n) {
                to_cut = max(to_cut, grid[i][j]);
            }
            fi(n) {
                curr[i][j] = min(to_cut, curr[i][j]);
            }
        }
        bool win = true;
        fi(n) {
            fj(m) {
                if (grid[i][j] != curr[i][j]) win = false;
            }
        }
        printf("Case #%d: ", Z);
        if (win) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

