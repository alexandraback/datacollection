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

int main()
{
    int t, n, a, w, d, r;
    scanf("%d", &t);
    FOR(cs, 1, t)
    {
        scanf("%d%d", &a, &n);
        VI mote(n);
        REP(x, n) scanf("%d", &mote[x]);
        w = INF;
        sort(ALL(mote));
        if(a == 1) w = n;
        else FOR(z, 0, n)
        {
            d = 0;
            r = a;
            REP(x, n - z)
            {
                while(mote[x] >= r)
                {
                    r += (r - 1);
                    d++;
                }
                r += mote[x];
            }
            w = min(w, d + z);
        }
        printf("Case #%d: %d\n", cs, w);
    }
    return 0;
}
