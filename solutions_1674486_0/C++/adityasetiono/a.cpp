#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

//#define FN "A-small"
#define FN "A-small-attempt2"
//#define FN "A-small-attempt1"
//#define FN "A-large"

int X,T;
int N,nlib;
int M[1024];
int inh[1024][12];
int lib[100000];

void crawl(int z)
{
    REP(i,M[z-1])
    {
        lib[nlib++] = inh[z-1][i];
        crawl(inh[z-1][i]);
    }
}

int main()
{
    freopen(FN ".in","r",stdin);
    freopen(FN ".out","w",stdout);

    scanf("%d",&T);
    FOR(X,1,T)
    {
        scanf("%d",&N);
        REP(i,N) 
        {
            scanf("%d",&M[i]);
            REP(j,M[i]) scanf("%d",&inh[i][j]);
        }
        
        bool diamond=false,sp=false;
        nlib=0;
        REP(i,N)
        {
            diamond = false;
            if (M[i]>1)
            {
                nlib=0;
                REP(j,M[i])
                {
                    lib[nlib++] = inh[i][j];
                    crawl(inh[i][j]);
                }
                if (nlib>1)
                {
                    sort(lib,lib+nlib);
                    REP(k,nlib-1) 
                    {
                        if(lib[k]==lib[k+1]) diamond=true;
                        if (diamond) break;
                    }
                }
                
            }
            if (diamond) break;
        }
        printf("Case #%d: ",X);
        if (diamond) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }
    return 0;
}

