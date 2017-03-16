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
#include <bitset>
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

string solve(int K, int C, int S)
{
    if (S < (K+C-1)/C) {
        return "IMPOSSIBLE";
    }
    
    vector<ll> ans;
    for (int i=0; i<K; i+=C) {
        vector<int> ns;
        for (int j=i; j<i+C && j<K; j++) {
            if (i==j) {
                if (i != 0)
                    ns.push_back(j);
            }
            else {
                ns.push_back(j);
            }
        }
        ll n = 0;
        REPV(ns, j) n = (ll)K*n+ns[ns.size()-j-1];
        ans.push_back(n);
    }

    ostringstream oss;
    REPV(ans, t) {
        if (t != 0)
            oss << " ";
        oss << ans[t]+1;
    }

    return oss.str();
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << _t+1 << ": " << solve(K, C, S) << endl;
    }

    return 0;
}
