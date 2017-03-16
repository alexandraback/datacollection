#include <time.h>
#include <stdlib.h>
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
    srand(time(NULL));
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t+1 << ":" << endl;
        int r, n, m, k;
        cin >> r >> n >> m >> k;
        int sol[15];
        int mult[15];
        REP(iii, r) {
            ZERO(sol);
            REP(i, k) {
                cin >> mult[i];
                sol[i] = 2;
            }
            //if (DEBUG) fprintf(stderr, "x\n");
            int primes[] = {2, 3, 5, 7};
            int nums[] = {5, 4, 3, 2};
            bool appears;
            int mm = 0, j = 0;
            int son1 = 0;
            while (j <  4 && son1 < k && mm < n) {
                appears = false;
                son1 = 0;
                REP(i, k) {
                    if (mult[i] == 1) son1++;
                    if (mult[i] % nums[j] == 0) {
                        mult[i] /= nums[j];
                        appears = true;
                    }
                }
                if (appears) {
                    sol[mm] = nums[j];
                    mm++;
                }
                else j++;
            }

            REP(i, n) {
                cout << sol[i];
            }
            cout << endl;
        }
    }
    return 0;
}
