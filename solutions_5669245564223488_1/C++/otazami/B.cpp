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

ll MOD=1000000007;
inline ll add_m(ll a, ll b) { return (a + b) % MOD; }
inline ll sub_m(ll a, ll b) { return (a - b + MOD) % MOD; }
inline ll mul_m(ll a, ll b) { return (a * b) % MOD; }
ll kaijo_m(int n)
{
    ll ret = 1LL;
    FORE(i, 1, n) {
        ret = mul_m(ret, (ll)i);
    }
    return ret;
}

bool checkValid(string s)
{
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
            cerr << "NG: " << s[lp] << endl;
            break;
        }
        if (p == L)
            break;
        cs.insert(s[lp]);
        lp = p;
    }
        
    return isValid;
}

bool isAllSame(string s)
{
    REPV(s, i) if (s[0] != s[i])
        return false;
    return true;
}

string norm(string s)
{
    string r;
    REPV(s, i) if (i == 0 || s[i] != s[i-1]) {
        r += s[i];
    }
    return r;
}

ll solve(void)
{
    int N;
    cin >> N;

    cerr << N << endl;
    vector<string> w(N);
    REP(i, N) {
        cin >> w[i];
        w[i] = norm(w[i]);
    }

    REP(i, N) {
        if (!checkValid(w[i]))
            return 0;
    }

    ll ret = 1LL;
    vector<bool> valid(N, true);
    REP(i, N) if (valid[i]) {
        if (isAllSame(w[i])) {
            int cnt = 1;
            REP(j, N) if (j != i && valid[j] && w[i][0] == w[j][0] && isAllSame(w[j])) {
                valid[j] = false;
                cnt++;
            }
            ret = mul_m(ret, kaijo_m(cnt));
        }
    }

    bool changed;
    do {
        changed = false;
        REP(i, N) if (valid[i]) {
            REP(j, N) if (j != i && valid[j] && w[i][0] == w[j][w[j].size()-1]) {
                w[j] += w[i].substr(1, w[i].size()-1);
                valid[i] = false;
                changed = true;
                goto LOOP_END;
            }
        }
      LOOP_END:;
    } while(changed);

    string as;
    int vcnt = 0;
    REP(i, N) if (valid[i]) {
        vcnt++;
        as += w[i];
    }

    if (!checkValid(as)) {
        cerr << "INVALID: " << as << endl;
        return 0;
    }

    ret = mul_m(ret, kaijo_m(vcnt));

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

