#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
#define _USE_MATH_DEFINES   // exposes constants M_PI
#define s(n)                scanf("%d",&n)
#define sl(n)               scanf("%lld",&n)
#define sf(n)               scanf("%lf",&n)
#define ss(n)               scanf("%s",n)
#define INF                 (1<<30)
#define LINF                (long long) 1E18
#define EPS                 std::numeric_limits<double>::epsilon()
#define ABS(x)              ((x)<0?-(x):(x))
#define FOR(i,a,b)          for(i=a; i<b; ++i)
#define RFOR(i,a,b)         for(i=(a)-1,_b(b); i>=_b; --i)
#define REP(i,n)            for((i)=0;(i)<(int)(n);++(i))
#define DREP(a)             sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)      (lower_bound(all(arr),ind)-arr.begin())
#define FOREACH(c,itr)      for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define mp                  make_pair
#define pb                  push_back
#define tri(a,b,c)          mp(a,mp(b,c))
#define fst                 first
#define snd                 second
#define FILL(a,v)           memset(a,v,sizeof(a))
#define SQR(a)              ((a)*(a))
#define MAX(a,b)            ((a)>(b)?(a):(b))
#define MIN(a,b)            ((a)<(b)?(a):(b))
#define ALL(x)              x.begin(),x.end()
#define SZ(v)               ((int)(v.size()))
#define LOG(a)              (cerr<<"line#"<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...)            (__VA_ARGS__)
#define debug(args...)      {cerr<<"case#";dbg,args;cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator, (const T& v) {
        cerr << v << " ";
        return *this;
    }
} dbg;
template<class T> T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}
typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       uint;
typedef pair<int, int>   PII;
typedef pair<LL, LL>     PLL;
typedef pair<int, PII>   TRI;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<string>  VS;
typedef vector<PII>     VII;
typedef vector<PLL>     VLL;
typedef vector<TRI>     VT;
typedef vector<VI>      VVI;
typedef vector<VL>      VVL;
typedef vector<VII>     VVII;
typedef vector<VLL>     VVLL;
typedef vector<VT>      VVT;
//typedef complex<double> pt;
//typedef complex<LL>     pti;
const double PI   = 3.1415926535897932384626433832795; //2*acos(0.0)
const float  PI_F = 3.14159265358979f;
double round(double x)
{
    const double sd = 100; //for accuracy to 2 decimal places
    return int(x * sd + (x < 0 ? -0.5 : 0.5)) / sd;
}
/////////////////////////////////////////////////////////////////////////////
const int MAXN = 2000001, MAXLEN = 8;
int cc, T;
LL i, j, A, B, n, num, reformed_num, offset, multiplier, pos, answer;
char sz_num[MAXLEN];
bool used[MAXN];
int main()
{
    //clock_t start = clock();
    scanf("%d", &T);
    REP(cc, T) {
        // for each test case
        scanf("%lld %lld", &A, &B);

        if(A <= 10 && B <= 10) {
            printf("Case #%d: 0\n", cc + 1);
            continue;
        }

        answer = 0;
        memset(used, false, MAXN);
        FOR(i, A, B + 1) { // i: number in question
            if(used[i])
                continue;

            used[i] = true;
            memset(sz_num, '\0', MAXLEN);

            // extract digits
            num = i;
            pos = 0;
            while(num > 0) { // pre: num != 0
                sz_num[pos++] = num % 10;
                num /= 10;
            }

            // check if all digits are identical
            int first_digit = -1;
            bool do_nothing = true;
            REP(j, pos) {
                if(j == 0)
                    first_digit = sz_num[j];
                else if(sz_num[j] != first_digit)
                    do_nothing = false;
            }
            if(do_nothing)
                continue;

            // form N numbers
            n = 1;
            FOR(offset, 1, pos) {
                reformed_num = 0;
                multiplier = 1;
                REP(j, pos) {
                    reformed_num += sz_num[(offset+j) % pos] * multiplier;
                    multiplier *= 10;
                }

                if(reformed_num >= A && reformed_num <= B) {
                    if (!used[reformed_num])
					{
                    	used[reformed_num] = true;
						n++;
					}
//					printf("num: %lld; reformed_num: %lld\n", i,reformed_num);
                }
            }
            answer += (n * (n - 1)) / 2;
        }
        printf("Case #%d: %lld\n", cc + 1, answer);
    }
    //fprintf(stderr, "*** Total time: %.3lf seconds ***\n",
    //        ((clock() - start) / (double) CLOCKS_PER_SEC));
    return 0;
}
