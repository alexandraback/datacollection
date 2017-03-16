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

int d, h, m, T, n;
pii a[100];


int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME"1.out", "w", stdout);

    scanf("%d", &T);
    forn(Q, T)
    {
        scanf("%d", &n);
        int cnt = 0;
        forn(i, n)
        {
            scanf("%d%d%d", &d, &h, &m);
            forn(j, h)
                a[cnt++] = mp(d, m + j);
        }
        int ans = 0;
        if (cnt == 2 && a[0].second != a[1].second)
        {
            if (a[0].second > a[1].second)
                swap(a[0], a[1]);
            int dist = a[0].first - a[1].first;
            if (dist <= 0)
                dist = 360 + dist;
            double t1 =a[1].second * (360.0 - a[0].first) / 360.0, t2 = dist / (360.0 / a[0].second - 360.0 / a[1].second);
            cerr << t1 << " " << t2 << endl;
            if (t1 >= t2)
                ans = 1;
        }
        printf("Case #%d: %d\n", Q + 1, ans);
    }
}


