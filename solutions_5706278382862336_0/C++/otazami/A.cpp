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

string solve(void)
{
    string in;
    cin >> in;
    REPV(in, i) if (in[i] == '/')
        in[i] = ' ';

    istringstream iss(in.c_str());
    ll P, Q;
    iss >> P >> Q;

    if (P == Q) {
        return "0";
    }

    ll R=P;
    int cnt = 0;
    int ret = -1;
    while(R != 0 && cnt <= 40) {
        assert(R < Q);
        R <<= 1;
        if (R >= Q) {
            R -= Q;
            if (ret == -1)
                ret = cnt+1;
        }
        cnt++;
    }

    if (cnt > 40)
        return "impossible";

    ostringstream oss;
    oss << ret;
    return oss.str();
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        //cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

