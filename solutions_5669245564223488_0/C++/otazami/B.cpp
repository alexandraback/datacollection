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

ll MOD= 1000000007LL;

ll solve(void)
{
    int N;
    cin >> N;

    vector<pair<string, int> > w(N);
    REP(i, N) {
        cin >> w[i].first;
        w[i].second = i;
    }

    sort(w.begin(), w.end());

    cerr << N << endl;

    ll ret = 0;
    do{
        string s;
        REP(i, N) {
            s += w[i].first;
        }

        set<char> cs;
        int L = s.size();
        bool isValid = true;
        int lp = 0;
        int p = 0;
        while(true) {
            while(p < L && s[lp] == s[p]) {
                p++;
            }
            if (cs.find(s[lp]) != cs.end()) {
                isValid = false;
                break;
            }
            if (p == L)
                break;
            cs.insert(s[lp]);
            lp = p;
        }
        //cerr << "S:" << s << "," << isValid << endl;
        if (isValid) {
            ret = (ret+1)%MOD;
        }
    } while(next_permutation(w.begin(), w.end()));

    return ret;
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": " << solve() << endl;
    }

    return 0;
}

