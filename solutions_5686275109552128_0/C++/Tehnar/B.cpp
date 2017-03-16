#define FNAME ""

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < (int) b; i++)
#define gcd __gcd
 
#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;
typedef vector <int> vi;

template <class T> T sqr(const T &a) {return a * a;}

set <int> s;
int n, x, T, cnt, ans, max1, a[40000];

int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    scanf("%d", &T);
    forn(TT, T)
    {
        scanf("%d", &n);
        max1 = 0;
        forn(i, n)
            scanf("%d", &a[i]), max1 = max(max1, a[i]);
        ans = 1e9, cnt = 0;
        forab(i, 1, max1 + 1)
        {
            cnt = 0;
            forn(j, n)
                cnt += (a[j] - 1) / i;
            ans = min(ans, cnt + i);
        }
         
        printf("Case #%d: %d\n", TT + 1, ans);
    }
}

