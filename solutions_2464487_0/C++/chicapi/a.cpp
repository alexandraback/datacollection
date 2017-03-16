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

typedef long long LL;
typedef long double LD;
typedef double D;
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

int main ()
{

    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int64_t r, t;
        cin >> r >> t;
        int64_t sol = 0;
        int64_t i = 0;
        while (t > 0) {
            int64_t pint = (r+i+1)*(r+i+1) - (r+i)*(r+i);
            if (DEBUG) fprintf(stderr, "b: %lld w: %lld\n", r+i+1, r+i);
            if (t >= pint) {
                sol++;
                t -= pint;
            }
            else break;
            i += 1;
            r++;
        }

        cout << "Case #" << tt+1 << ": " << sol << endl;
    }
    return 0;
}
