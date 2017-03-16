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

int can(int N, vector<double> wN, vector<double> wK, int score)
{
    REP(i, N-score) {
        wN.erase(wN.begin());
        wK.pop_back();
    }
    REP(i, score) {
        if (wN[i] < wK[i]) {
            return false;
        }
    }
    return true;
}

int solveA(int N, vector<double> wN, vector<double> wK)
{
    sort(wN.begin(), wN.end());
    sort(wK.begin(), wK.end());

    int l = 0;
    int r = N;
    while(l <= r) {
        int m = (l+r)/2;
        if (can(N, wN, wK, m))
            l = m+1;
        else
            r = m-1;
    }

    return r;
}

int solveB(int N, vector<double> wN, vector<double> wK)
{
    vector<bool> used(N, false);
    int score = N;

    REP(i, N) {
        int findJ = -1;
        REP(j, N) if (!used[j] && (findJ == -1 || wK[findJ] > wK[j])) {
            if (wN[i] < wK[j]) {
                findJ = j;
            }
        }
        if (findJ != -1) {
            used[findJ] = true;
            --score;
        }
    }
    return score;
}

pair<int, int> solve(void)
{
    int N;
    cin >> N;

    vector<double> wN(N);
    vector<double> wK(N);

    REP(i, N)
        cin >> wN[i];
    REP(i, N)
        cin >> wK[i];

    return make_pair<int, int>(solveA(N, wN, wK), solveB(N, wN, wK));
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        //cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ": ";
        pair<int,int> ret = solve();
        cout << ret.first << " " << ret.second << endl;
    }

    return 0;
}

