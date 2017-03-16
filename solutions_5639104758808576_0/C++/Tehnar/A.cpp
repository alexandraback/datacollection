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

int t, n, cnt, ans;
char s[3000];

int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    scanf("%d\n", &t);
    forn(q, t)
    {
        scanf("%d %s", &n, s);
        cnt = ans = 0;
        forn(i, n + 1)
        {
            if (cnt < i)
                ans += i - cnt, cnt = i;
            cnt += s[i] - '0';
        }
        printf("Case #%d: %d\n", q + 1, ans);
    }

}

