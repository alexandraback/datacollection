//----------------------------------------------------------------------------//
//############################################################################//
//----------------------------------------------------------------------------//
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
using namespace std;
//----------------------------------------------------------------------------//
//############################################################################//
//----------------------------------------------------------------------------//
// Iterate i from 0 to n-1
#define REP(i,n) for(int i=0;i<(n);++i)
// Iterate i from p to k (p <= k)
#define FOR(v,p,k) for(int v=p;v<=k;++v)
// Iterate i from p to k (p >= k)
#define RFOR(v,p,k) for(int v=p;v>=k;--v)
// Iterate i over all elements in c
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
// Sort c
#define SORT(c) sort(c.begin(), c.end())
// Reverse sort c
#define RSORT(c) sort(c.rbegin(), c.rend())
// Everything in c
#define ALL(c) c.begin(),c.end()
// Zero x
#define ZERO(x) memset(x,0,sizeof(x))
// Set v to i
#define VAR(v,i) __typeof(i) v=(i)
// Get size of x
#define SIZE(x) (int)x.size()
// Make a pair
#define MP make_pair
// Push back
#define PB push_back
// 
#define MAX(a,b) ((a)>(b)?(a):(b))
// 
#define MIN(a,b) ((a)<(b)?(a):(b))
//----------------------------------------------------------------------------//
//############################################################################//
//----------------------------------------------------------------------------//
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
const double PI = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
//############################################################################//
//----------------------------------------------------------------------------//
//#define DEBUG
#ifdef DEBUG
#define dprint(fmt) fprintf(stderr,fmt)
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprint(fmt)
#define dprintf(fmt,...)
#endif
//----------------------------------------------------------------------------//
//############################################################################//
//----------------------------------------------------------------------------//

void solveCase(){
    int A,B;
    scanf("%d %d", &A, &B);
    double p[A];
    REP(i,A){
        cin >> p[i];
    }
    
    double res1, res2, res3;
    // first strategy ----------------------------------------------------------
    res1=0;
    double prod = 1;
    REP(n,A){
        prod *=p[n];
    }
    res1=prod*(B-A+1)+(1-prod)*(2*B-A+2);
    // third strategy ----------------------------------------------------------
    res3 = B+2;
    // second strategy ---------------------------------------------------------
    res2=1000000000;
    FOR(b,1,A){
        prod = 1;
        REP(bi,A-b){
            prod *=p[bi];
        }
        double prob =prod*(B-(A-b)+b+1)+(1-prod)*(2*B-(A-b)+b+2);
        res2 = MIN(prob,res2);
    }
    
    //
    double tmp = MIN(res1,res2);
    tmp = MIN(tmp,res3);
    printf("%lf\n",tmp);
    
}

int main(){
    int T;
    scanf("%d",&T);
    REP(t,T){
        printf("Case #%d: ",t+1);
        solveCase();
    }
}

