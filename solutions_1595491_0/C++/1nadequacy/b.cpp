#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

int f[128][128];
int a[128];
int n, s, p;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        scanf("%d %d %d", &n, &s, &p);
        forn (i, n) scanf("%d", a+i);
        forn (i, 128) forn (j, 128) f[i][j] = -1;
        f[0][0] = 0;
        forn (i, n) forn (j, s+1) if (f[i][j] != -1)
        {
            forn (x, 11) forn (q1, 3) forn (q2, 3) if (3*x+q1+q2 == a[i])
            {
                int m = max(x+q1, x+q2);
                int add = m >= p;
                if (q1 == 2 || q2 == 2)
                    f[i+1][j+1] = max(f[i+1][j+1], f[i][j]+add);
                else
                    f[i+1][j] = max(f[i+1][j], f[i][j]+add);
            }
        }
        int res = 0;
        forn (i, s+1) res = max(res, f[n][i]);
        printf("Case #%d: %d\n", tt, res);
    }

    return 0;
}
