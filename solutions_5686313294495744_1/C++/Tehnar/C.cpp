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

const int MAXN = 1010;

map<string, int> Map[2];
string s[MAXN][2];
char ttt[30], tttt[30];
int T, n, used[MAXN], inMatch[MAXN], Pair[MAXN], sz[MAXN];
vi a[MAXN];

int dfs(int v) {
    used[v] = 1;
    for (int to : a[v]) {
        if (Pair[to] == -1 || (!used[Pair[to]] && dfs(Pair[to]))) {
            Pair[to] = v, inMatch[v] = 1;
            return 1;
        }
    }
    return 0;
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
            s[i][0] = ttt, s[i][1] = tttt;        
            sz[i] = 0;
        }
        Map[0].clear(), Map[1].clear();
        forn(i, n) {
            forn(j, 2)
                if (!Map[j].count(s[i][j])) {
                    int sz = Map[j].size();
                    Map[j][s[i][j]] = sz;
                }
        }
        if (Map[0].size() < Map[1].size()) {
            swap(Map[0], Map[1]);
            forn(i, n)
                swap(s[i][0], s[i][1]);
        }
        forn(i, (int) Map[0].size())
            a[i].clear();
        forn(i, n) {
//            printf("edge (%d,%s)->(%d,%s)\n", Map[0][s[i][0]], s[i][0].c_str(), Map[1][s[i][1]], s[i][1].c_str());
            a[Map[0][s[i][0]]].pb(Map[1][s[i][1]]), inMatch[i] = 0;    
            sz[Map[1][s[i][1]]]++;
        }
  /*      forn(i, (int) Map[0].size())
            for (int to : a[i])
                printf("edge (%d)->(%d)\n", i, to);*/
        forn(i, (int) Map[1].size())
            Pair[i] = -1;        
        int ok = 1;
        while (ok) {
            ok = 0;
            forn(i, (int) Map[0].size())
                used[i] = 0;
            forn(i, (int) Map[0].size())
                if (!used[i] && !inMatch[i] && dfs(i))
                    ok = 1;
        }
                  /*
        forn(i, (int) Map[0].size()) {
            if (!inMatch[i] && a[i].size() >= 2) {
                inMatch[i] = 1;
                for (int to : a[i])
                    if (Pair[to] == -1) {
                        Pair[to] = i;
                        break;
                    }
            }
        }
                */
        int ans = n - Map[1].size();
        forn(i, (int) Map[0].size()) {
            if (!inMatch[i]) {
                ans--;
            } 
            /*for (int to : a[i])
                    if (Pair[to] != -1)
                        ans++;
            } */
        }       /*
        forn(i, (int) Map[1].size())
            if (Pair[i] == -1)
                ans--; */
        printf("Case #%d: %d\n", qq + 1, ans);
    }
}

