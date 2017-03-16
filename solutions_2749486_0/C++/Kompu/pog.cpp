#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
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
    int t;
    PI end;
    scanf("%d", &t);
    FOR(cs, 1, t)
    {
        scanf("%d%d", &end.ST, &end.ND);
        PI begin;
        printf("Case #%d: ", cs);
        if(begin.ST != end.ST)
        {
            if(begin.ST < end.ST) REP(x, end.ST - begin.ST) printf("WE");
            else REP(x, begin.ST - end.ST) printf("EW");
        }
        if(begin.ND != end.ND)
        {
            if(begin.ND < end.ND) REP(x, end.ND - begin.ND) printf("SN");
            else REP(x, begin.ND - end.ND) printf("NS");
        }
        printf("\n");
    }
    return 0;
}
