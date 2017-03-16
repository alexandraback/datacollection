
//Tomasz Kulczyński
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdlib>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }

#include <cassert>

int brut(VI a, VI b, int n) {
    int ret = 2012;
    REP(mask, 1<<n) {
        VI t;
        int w = 0;
        REP(i, n) if(mask & (1<<i))  {
            t.PB(a[i]);
            t.PB(b[i]);
            w += 2;
        }
        else {
            t.PB(b[i]);
            t.PB(b[i]);
            w++;
        }
        sort(ALL(t));
        REP(i, SIZE(t)) if(t[i] > i) 
            w = 2012;
        ret = min(ret, w);
    }
    return ret >= 2012 ? -1 : ret;
}

int solve(VI a, VI b, int n) {
    VI c(n, 0);
    int x = 0, ret = 0;
    while(x < n+n) {
        bool ok = 0;
        REP(i, n) if(c[i] < 2 && b[i] <= x) {
            ok = 1;
            x += 2 - c[i];
            ret++;
            c[i] = 2;
        }
        if(ok) continue;
        int i = -1;
        REP(j, n) if(!c[j] && a[j] <= x && (i == -1 || b[j] > b[i]))
            i = j;
        if(i == -1)
            return -1;
        x++;
        c[i] = 1;
        ret++;
    }
    return ret;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    FOR(cas, 1, tt) {
        int n;
        scanf("%d",&n);
        vector<int> a(n), b(n);
        REP(i, n) scanf("%d %d",&a[i],&b[i]);
        int res = solve(a, b, n);
        if(n < 15)
            assert(brut(a, b, n) == res);
        printf("Case #%d: ",cas);
        if(res == -1)
            puts("Too Bad");
        else
            printf("%d\n",res);
    }
    return 0;
}
