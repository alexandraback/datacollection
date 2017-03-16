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

#define MAX_N ((size_t)1<<32)

vector<int> getPrime(int n) {
    vector<int> ret;
    FORE(i, 2, n) {
        bool ok = true;
        int k = (int)floor(sqrt((double)i)+EPS);
        for (unsigned int j = 0; j < ret.size() && ret[j] <= k; ++j) {
            if (i % ret[j] == 0) {
                ok = false;
                break;
            }
        }
        if (ok)
            ret.push_back(i);
    }
    return ret;
}

int solve(int N, int J)
{
    vector<int> primes = getPrime(100000);

    int cnt = 0;
    int bits[32];
    for (ll i=(1LL<<(N-1))+1; i<(1LL<<N); i+=2) {
        ll n = i;
        REP(j, N) {
            int b = (n % 2LL);
            bits[N-j-1] = b;
            n /= 2LL;
        }

        //REP(j, N)
        //cerr << bits[N-j-1];
        //cerr << endl;

        assert(bits[0] == 1);
        assert(bits[N-1] == 1);
        bint nums[11] = {0};
        FORE(d, 2, 10) {
            REP(j, N) {
                nums[d] = (bint)d*nums[d] + (bint)bits[j];
            }
            //cerr << nums[d] << endl;
        }
        bool ok = true;
        vector<int> div;
        FORE(d, 2, 10) {
            bool canD = false;
            for (int j=0; j < (int)primes.size() && primes[j] < nums[d]/*&& (ll)primes[j]*(ll)primes[j]<=nums[d]*/; j++) {
                if (nums[d]%primes[j] == 0) {
                    assert(primes[j] < nums[d]);
                    div.push_back(primes[j]);
                    canD = true;
                    break;
                }
            }
            if (!canD) {
                ok = false;
                break;
            }
        }
        if (ok) {
            REP(j, N)
                cout << bits[j];
            REPV(div, j)
                cout << " " << div[j];
            //FORE(d, 2, 10)
            //    cerr << "TEST: " << nums[d] << endl;
            cout << endl;
            ++cnt;
            if (cnt == J)
                return 0;
        }
    }

    return 1;
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        int N, J;
        cin >> N >> J;
        cout << "Case #" << _t+1 << ":" << endl;
        solve(N, J);
    }

    return 0;
}
