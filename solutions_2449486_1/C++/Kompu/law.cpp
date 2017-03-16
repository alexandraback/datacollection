#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef long long LL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

struct Trawnik
{
    int n, m;
    VVI wzo, sym;
    Trawnik(int a, int b) : n(a), m(b), wzo(n, VI(m)), sym(n, VI(m, INF)) { }
    void CutOX(int i, int h)
    {
        REP(x, m) sym[i][x] = min(sym[i][x], h);
    }
    void CutOY(int i, int h)
    {
        REP(x, n) sym[x][i] = min(sym[x][i], h);
    }
    void Compute()
    {
        int w;
        REP(x, n)
        {
            w = 0;
            REP(y, m) w = max(w, wzo[x][y]);
            CutOX(x, w);
        }
        REP(x, m)
        {
            w = 0;
            REP(y, n) w = max(w, wzo[y][x]);
            CutOY(x, w);
        }
    }
    bool Compare()
    {
        REP(x, n) REP(y, m) if(wzo[x][y] != sym[x][y]) return false;
        return true;
    }
};
int main()
{
    int t, n, m;
    scanf("%d", &t);
    FOR(cs, 1, t)
    {
        scanf("%d%d", &n, &m);
        Trawnik k(n, m);
        REP(x, n) REP(y, m) scanf("%d", &k.wzo[x][y]);
        k.Compute();
        printf("Case #%d: ", cs);
        if(k.Compare()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
