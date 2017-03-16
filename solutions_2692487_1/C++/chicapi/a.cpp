#include <inttypes.h>
#include <sys/types.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

typedef uint64_t LL;
typedef long double LD;
typedef uint64_t D;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

#ifndef DEBUG
#define DEBUG 0
#endif

static int
cmp(const void *p1, const void *p2)
{
   return (* (int64_t * const *) p1 > * (int64_t * const *) p2);
}

int main ()
{

    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int a, n;
        int64_t sz[100+1];
        cin >> a >> n;
        ZERO(sz);
        REP(i, n)
        {
            cin >> sz[i];
        }
        qsort(sz, n, sizeof(sz[0]), cmp);
        //cout << a << " " << n << endl;
        //REP(i, n)
        //{
            //cout << sz[i] << " ";
        //}
        //cout << endl;
        int64_t sol = 0, sol_remove = n*2;
        int64_t M = a;
        REP(i, n)
        {
            if (M > sz[i])
            {
                M += sz[i];
                continue;
            }
            if (M + M - 1 > sz[i]) // (add < M)
            {
                sol++;
                M += M - 1;
                M += sz[i];
                continue;
            }
            sol_remove = MIN(sol_remove, sol + n - i);
            if (M - 1 == 0)
            {
                sol += (n - i);
                goto done;
            }
            while (M <= sz[i])
            {
                M += M - 1;
                sol++;
            }
            M += sz[i];
            continue;
        }
        //cout.precision(0);
done:
        /*if (M == a)
        {
            sol = sol_remove;
        } */
        sol = MIN(sol, sol_remove);
        //cout << M << endl;
        cout << "Case #" << tt+1 << ": " << sol << endl;
    }
    return 0;
}

