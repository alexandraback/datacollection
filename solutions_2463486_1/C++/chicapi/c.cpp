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
#include <inttypes.h>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

typedef vector<int> VI;
typedef pair<int,int> PII;
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

uint64_t fq1000[39+1] = { 1 /* 1 */,  4 /* 2 */,  9 /* 3 */,  121 /* 11 */,  484 /* 22 */,
10201 /* 101 */,  12321 /* 111 */,  14641 /* 121 */, 40804 /* 202 */,  44944 /* 212 */,
1002001 /* 1001 */,  1234321 /* 1111 */, 4008004 /* 2002 */,
100020001 /* 10001 */,  102030201 /* 10101 */,  104060401 /* 10201 */,  121242121 /* 11011 */,  123454321 /* 11111 */,
125686521 /* 11211 */,  400080004 /* 20002 */,  404090404 /* 20102 */,
10000200001 /* 100001 */,  10221412201 /* 101101 */,  12102420121 /* 110011 */,
12345654321 /* 111111 */, 40000800004 /* 200002 */,
1000002000001 /* 1000001 */,  1002003002001 /* 1001001 */,  1004006004001 /* 1002001 */,  1020304030201 /* 1010101 */,
1022325232201 /* 1011101 */,  1024348434201 /* 1012101 */,  1210024200121 /* 1100011 */,  1212225222121 /* 1101011 */,
1214428244121 /* 1102011 */,  1232346432321 /* 1110111 */,  1234567654321 /* 1111111 */,  4000008000004 /* 2000002 */,
4004009004004 /* 2001002 */,  0 };

int main ()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        uint64_t a, b;
        cin >> a >> b;
        int sol = 0;
        for (int i = 0; fq1000[i]; i++) {
            if (a <= fq1000[i] && fq1000[i] <= b)
                sol++;
        }
        cout << "Case #" << t+1 << ": " << sol << endl;
    }
    return 0;
}

