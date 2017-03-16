#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <climits> 
#include <cfloat> 
#include <map> 
#include <utility> 
#include <set> 
#include <iostream> 
#include <memory> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <sstream> 
#include <complex> 
#include <stack> 
#include <queue> 
#include <numeric>
#include <cassert>
#include <gmpxx.h>

#define FOR(i, min, max) for (int i = (min); i < (max); ++i) 
#define FORE(i, min, max) for (int i = (min); i <= (max); ++i) 
#define REP(i, n) for (int i = 0; i < (n); ++i) 
#define REPV(vec, i) for (int i = 0; i < (int)(vec.size()); ++i) 
#define FOR_EACH(vec, it) for (typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); ++it)

using namespace std; 
static const double EPS = 1e-12; 
typedef long long ll; 
typedef mpz_class bint;

int solve(string N)
{
    int size = N.size();
    reverse(N.begin(), N.end());
    int ret = 0;
    REP(i, size) {
        if (N[i] == '-') {
            ++ret;
            FOR(j, i, size) {
                if (N[j] == '-') N[j] = '+';
                else             N[j] = '-';
            }
        }
    }

    return ret;
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        string N;
        cin >> N;
        cout << "Case #" << _t+1 << ": " << solve(N) << endl;
    }

    return 0;
}
