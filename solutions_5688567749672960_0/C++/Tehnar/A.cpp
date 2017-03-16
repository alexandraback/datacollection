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

const int MAXN = 1e6 + 10000;
int T, n;
int d[MAXN];
set <pair <int, int> > q;

int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME"1.out", "w", stdout);

    scanf("%d", &T);
    d[0] = 0;
    q.insert(mp(0,0));
    forab(i, 1, MAXN)
        q.insert(mp(1e9, i)), d[i] = 1e9;
    while (q.size())
    {
        int v=  q.begin()->second;
        q.erase(q.begin());
        if (v + 1 < MAXN && d[v + 1] > d[v] + 1)
        {
            q.erase(mp(d[v + 1], v + 1));
            d[v + 1] = d[v] + 1;
            q.insert(mp(d[v + 1], v + 1));
        }
        int x = 0, y = v;
        while (y)
            x = x * 10 + y % 10, y /= 10;
        if (x < MAXN && d[x] > d[v] + 1)
        {
            q.erase(mp(d[x], x));
            d[x] = d[v] + 1;
            q.insert(mp(d[x], x));
        }
    }
    forn(q, T)
    {
        scanf("%d", &n);
        printf("Case #%d: %d\n", q + 1, d[n]);
    }
}


