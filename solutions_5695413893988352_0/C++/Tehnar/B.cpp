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

int can[2][10000];
char s[10000], t[10000];
int T, d[10000];

int main()
{
#ifdef LOCAL
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
#endif

    scanf("%d ", &T);
    forn(qq, T) {
        scanf("%s %s ", s, t);
        
        forn(i, 1001)
            can[0][i] = can[1][i] = 0;
        forn(k, 2) {
            int n = strlen(s);                
            forn(i, 1000) {
                int len = 0;
                int x = i;
                forn(j, n)
                    d[j] = 0;
                if (i == 0)
                    len = 1;
                else { 
                    while (x > 0) {
                        d[len++] = x % 10;
                        x /= 10;
                    }
                    reverse(d, d + n);
                }
                if (len > n)
                    continue;
                int ok = 1;
                forn(j, n)
                    if (d[j] != s[j] - '0' && s[j] != '?')
                        ok = 0;
                if (ok) 
                    can[k][i] = 1;
            }
            swap(s, t);
        }
        int diff = 1e9;
        pii ans;
        forn(i, 1001)
            forn(j, 1001)
                if (can[0][i] && can[1][j] && abs(i - j) <= diff) {
                    if (abs(i - j) < diff)
                        ans = mp(i, j);
                    diff = abs(i - j);
                    ans = min(ans, mp(i, j));
                }
        int n = strlen(s), m = strlen(t);
        printf("Case #%d: ", qq + 1);
        forn(i, n - to_string(ans.first).length())
            printf("0");
        printf("%d ", ans.first);
        forn(i, m - to_string(ans.second).length())
            printf("0");
        printf("%d", ans.second);
        puts("");

    }
}

