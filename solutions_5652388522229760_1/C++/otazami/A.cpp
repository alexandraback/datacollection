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

string solve(string N)
{
    set<char> w;
    reverse(N.begin(), N.end());
    string oN = N;
    int tryCount = 0;
    while(true) {
        REPV(N, i) {
            if (w.find(N[i]) == w.end()) {
                w.insert(N[i]);
            }
            if (w.size() == 10) {
                reverse(N.begin(), N.end());
                return N;
            }
        }
        char carry = 0;
        REPV(N, i) {
            char d = (i < (int)oN.size()) ? (N[i]+oN[i]+carry-'0') : (N[i]+carry);
            if (d > '9') {
                carry = 1;
                d -= 10;
            }
            else {
                carry = 0;
            }
            N[i] = d;
            assert(carry <= 1);
        }
        if (carry)
            N += "1";
        ++tryCount;
        if (tryCount == 100000)
            return "INSOMNIA";
    }

    return string();  // cannot reach
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
