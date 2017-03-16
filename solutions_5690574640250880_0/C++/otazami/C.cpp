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

int R, C, M;
int dr[8] = {-1, 0, 1, 0, -1, -1,  1, 1};
int dc[8] = { 0,-1, 0, 1, -1,  1, -1, 1};

bool isIN(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

void visit(vector<string> &w, vector<vector<bool> > &visited, int r, int c) {
    assert(w[r][c] == '.');

    if (visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    REP(d, 8) {
        int tr = r + dr[d];
        int tc = c + dc[d];
        if (isIN(tr, tc) && w[tr][tc] == '.') {
            visit(w, visited, tr, tc);
        }
    }
}

bool can(vector<string> &ans) {

    vector<string> w = ans;
    if (M == R*C-1) {
        // ok
    } else {
        REP(r, R) REP(c, C) if (ans[r][c] == '*') {
            REP(d, 8) {
                int tr = r + dr[d];
                int tc = c + dc[d];
                if (isIN(tr, tc) && w[tr][tc] == '.') {
                    w[tr][tc] = 'x';
                }
            }
        }

        REP(r, R) REP(c, C) if (w[r][c] == 'x') {
            bool adjS = false;
            REP(d, 8) {
                int tr = r + dr[d];
                int tc = c + dc[d];
                if (isIN(tr, tc) && w[tr][tc] == '.') {
                    adjS = true;
                }
            }
            if (!adjS) {
                return false;  // cannot
            }
        }

        vector<vector<bool> > visited(R, vector<bool>(C, false));
        bool first = true;
        REP(r, R) REP(c, C) if (w[r][c] == '.' && !visited[r][c]) {
            if (!first) {
                return false;
            }
            visit(w, visited, r, c);
            first = false;
        }
    }

#if 0
    cerr << "----" << endl;
    REP(r, R)
        cerr << w[r] << endl;
#endif

    REP(r, R) REP(c, C) if (w[r][c] == '.') {
        ans[r][c] = 'c';
        return true;
    }

    // cannot reach

    return true;
}

vector<string> solve(void)
{
    cin >> R >> C >> M;
   
    int sizeRC = R*C;

    REP(i, (1<<sizeRC)) {
        if (__builtin_popcount(i) == M) {
            vector<string> ans(R, string(C, '.'));
            REP(r, R) REP(c, C) {
                int pos = r*C + c;
                if ((i & (1<<pos))) {
                    ans[r][c] = '*';
                } else {
                    ans[r][c] = '.';
                }
            }

            if (can(ans)) {
                return ans;
            }
        }
    }

    return vector<string>();
}

int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        //cerr << _t+1 << "/" << T << endl;
        cout << "Case #" << _t+1 << ":" << endl;
        vector<string> ans = solve();
        if (ans.empty()) {
            cout << "Impossible" << endl;
        } else {
            REPV(ans, i) {
                cout << ans[i] << endl;
            }
        }
    }

    return 0;
}

