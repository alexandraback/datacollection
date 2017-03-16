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

const int maxn = 1000;

int a[maxn];
int n;
int sum;

double solve(int i)
{
    ld l = 0, r = 1;
    forn (it, 300)
    {
        ld mid = (l+r)*0.5;
        ld sx = mid;
        forn (j, n) if (i!=j) if (a[i]+sum*mid > a[j]) sx += (a[i]+sum*mid-a[j])/sum;
        if (sx < 1) l = mid; else r = mid;
    }
    return 100*l;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        scanf("%d", &n);
        sum = 0;
        forn (i, n) scanf("%d", a+i), sum += a[i];
        printf("Case #%d:", tt);
        forn (i, n) printf(" %.10f", solve(i));
        puts("");

    }

    return 0;
}
