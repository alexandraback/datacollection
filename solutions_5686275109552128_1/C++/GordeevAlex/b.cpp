#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

const int MAXN = 1010;

int n;
int cnt[MAXN];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d ", &T);
    forn(test, T) {
        printf("Case #%d: ", test + 1);

        memset(cnt, 0, sizeof(cnt));

        scanf("%d", &n);

        int mx = 1;

        forn(i, n) {
            int p;
            scanf("%d", &p);

            mx = max(mx, p);

            cnt[p]++;
        }

        int ans = mx;

        forab(i, 1, mx) {
            int cur = i;
            forab(j, 1, mx + 1)
                cur += cnt[j] * ((j - 1) / i);

            ans = min(ans, cur);
        }

        printf("%d\n", ans);

    }
    return 0;
}
