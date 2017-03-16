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

void color(vector<vector<int> > &B, int i, int j)
{
    int isize = B.size();
    int jsize = B[0].size();

    if (0 <= i && i < isize && 0 <= j && j < jsize && B[i][j] == 0) {
        B[i][j] = -1;
        color(B, i-1,   j);
        color(B, i+1,   j);
        color(B,   i, j-1);
        color(B,   i, j+1);
    }
}

int getCount(vector<vector<int> > B)
{
    int isize = B.size();
    int jsize = B[0].size();
    REP(i, isize) {
        color(B, i, 0);
        color(B, i, jsize-1);
    }
    REP(j, jsize) {
        color(B, 0, j);
        color(B, isize-1, j);
    }
    int cnt = 0;
    REP(i, isize) REP(j, jsize) if (B[i][j] != -1)
        ++cnt;
    return cnt;
}

int solve(void)
{
    int isize, jsize, K;
    cin >> isize >> jsize >> K;

    int NM = isize*jsize;
    int ret = INT_MAX;
    REP(mask, (1<<NM)) {
        vector<vector<int> > B(isize, vector<int>(jsize, 0));
        REP(i, isize) REP(j, jsize) {
            int ij = i*jsize + j;
            if (mask & (1<<ij))
                B[i][j] = 1;
        }
        int cnt = getCount(B);
        if (cnt >= K) {
            ret = min(ret, __builtin_popcount(mask));
        }
    }

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
