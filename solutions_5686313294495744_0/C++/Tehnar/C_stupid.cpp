#define FNAME ""

#include <bits/stdc++.h>

#define hash padjf9srpi
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
 
#ifdef _WIN32
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

int n, T, g[1<<16];
pair <string, string> s[20];
char ttt[100], tttt[1000];

int f(int mask) {
    if (g[mask] != -1)
        return g[mask];
    g[mask] = 0;
    forn(i, n) {
        if (mask & (1<<i)) {
            int newmask = mask ^ (1<<i);
            int cnt = f(newmask);
            set <string> used[2];
            forn(j, n) {
                if (newmask & (1<<j))
                    used[0].insert(s[j].first), used[1].insert(s[j].second);                                
            }
            g[mask] = max(g[mask], cnt + (used[0].count(s[i].first) && used[1].count(s[i].second)));
        }
    }
    return g[mask];
}

int main()
{
#ifdef LOCAL
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
#endif

    scanf("%d", &T);
    forn(qq, T) {
        scanf("%d ", &n);
        forn(i, n) {
            scanf("%s %s ", ttt, tttt);
            s[i] = mp(string(ttt), string(tttt)); 
        }
        forn(i, 1<<n)
            g[i] = -1;
        printf("Case #%d: %d\n", qq + 1, f((1<<n) - 1));
        cerr << qq << " " << T << endl;
    }
}

