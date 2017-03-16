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


int a[32];
int n;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        scanf("%d", &n);
        forn (i, n) scanf("%d", a+i);
        map<int,int> ma;
        printf("Case #%d:\n", tt);
        forn (i, (1<<n)) if (i)
        {
            int s = 0;
            forn (j, n) if (i&(1<<j)) s += a[j];
            if (ma.count(s))
            {
                int q = ma[s];
                forn (j, n) if (q&(1<<j)) printf("%d ", a[j]); puts("");
                forn (j, n) if (i&(1<<j)) printf("%d ", a[j]); puts("");
                goto end;
            }
            else ma[s] = i;
        }
        puts("Impossible");
end:;
        
    }

    return 0;
}
