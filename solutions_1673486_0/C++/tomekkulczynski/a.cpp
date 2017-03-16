
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

double wynik(const double& p, int i, int a, int b) {
    return (a-i + b-i + 1) + (1 - p) * (b + 1);
}

double licz(int a, int b, const vector<double>& x) {
    double ret = 2 + b, p = 1;
    FOR(i, 0, a) {
        ret = min(ret, wynik(p, i, a, b));
   //     printf("%.6lf\n",wynik(p, i, a, b));
        p *= x[i];
    }
    return ret;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    FOR(cas, 1, tt) {
        int a, b;
        scanf("%d %d",&a,&b);
        vector<double> x(a);
        REP(i, a) scanf("%lf",&x[i]);
        printf("Case #%d: %.8lf\n", cas, licz(a, b, x));
    }
    return 0;
}
