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

bool can(vector<string> &ans, bool checkC = false) {

    int cposR = -1;
    int cposC = -1;
    if (checkC) {
        REP(r, R) REP(c, C) if (ans[r][c] =='c') {
            cposR = r;
            cposC = c;
            ans[r][c] = '.';
        }
    }

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

    if (checkC) {
        return w[cposR][cposC] == '.';
    } else {
        REP(r, R) REP(c, C) if (w[r][c] == '.') {
            ans[r][c] = 'c';
            return true;
        }
    }

    // cannot reach

    return true;
}

bool canRect(int s, int &recR, int &recC)
{
    FORE(r, 2, R) {
        if (s % r == 0) {
            int c = s / r;
            if (2 <= c && c <= C) {
                recR = r;
                recC = c;
                return true;
            }
        }
    }

    return false;
}

bool canKaidan(vector<int> &ansK)
{
    static int mem[64][2600];
    static int fromC[64][64][2600];

    memset(mem, 0, sizeof(mem));

    FORE(c, 1, C) {
        if (c != C-1) {
            mem[c][c] = 1;
            fromC[1][c][c] = 0;
        }
    }

    FOR(r, 1, R) {
        static int nmem[64][2600];
        memset(nmem, 0, sizeof(nmem));
        FORE(c, 0, C) REP(m, M+1) if (mem[c][m]) {
            if (r == R-1) {
                nmem[c][m+c] = 1;
                fromC[r+1][c][m+c] = c;
            } else {
                int maxC = c;
                if (r <= R-2) {
                    maxC = min(maxC, C-2);
                }
                FORE(nc, 0, maxC) {
                    if (nc != C-1) {
                        int nm = m+nc;
                        nmem[nc][nm] = 1;
                        fromC[r+1][nc][nm] = c;
                    }
                }
            }
        }
        memcpy(mem, nmem, sizeof(mem));
    }
    
    int lastC = -1;
    REP(c, C) if (mem[c][M]) {
        lastC = c;
        break;
    }

    ansK.clear();
    if (lastC != -1) {
        int curC = lastC;
        int curM = M;
        ansK.resize(R);
        for (int r = R; r > 0; --r) {
            ansK[r-1] = curC;
            int nC = fromC[r][curC][curM];
            int nM = curM-curC;
            curC = nC;
            curM = nM;
        }

        return true;
    }

    return false;
}

vector<string> solve(void)
{
    cin >> R >> C >> M;
    bool swaped = false;

    if (R > C) {
        swaped = true;
        swap(R, C);
    }
    assert(R <= C);

    int S = R*C-M;
    vector<string> ans;
    if (M == 0) {
        ans = vector<string>(R, string(C, '.'));
        ans[0][0] = 'c';
    } else if (S == 1) {
        ans = vector<string>(R, string(C, '*'));
        ans[R-1][C-1] = 'c';
    } else if (R == 1) {
        ans = vector<string>(R, string(C, '.'));
        REP(c, M)
            ans[0][c] = '*';
        ans[0][M+1] = 'c';
    } else if (R == 2) {
        bool ok = (M%2 == 0 && S != 2);
        if (ok) {
            ans = vector<string>(R, string(C, '.'));
            REP(c, M/2) {
                ans[0][c] = ans[1][c] = '*';
            }
            ans[0][M/2+1] = 'c';
        } else {
            // ng
        }
    } else if (S == 2 || S == 3 || S == 5 || S == 7) {
        // ng
    } else {
        int recR = -1;
        int recC = -1;
        vector<int> ansK;
        if (M/C <= R-3 && M%C <= C-2) {
            int maxR = M/C;
            int maxC = M%C;
            ans = vector<string>(R, string(C, '.'));
            REP(r, maxR)
                ans[r] = string(C, '*');
            REP(c, maxC)
                ans[maxR][c] = '*';
            ans[maxR+1][maxC+1] = 'c';
        }
        else if (M/R <= C-3 && M%R <= R-2) {
            int maxC = M/R;
            int maxR = M%R;
            ans = vector<string>(R, string(C, '.'));
            REP(c, maxC) {
                REP(r, R) {
                    ans[r][c] = '*';
                }
            }
            REP(r, maxR)
                ans[r][maxC] = '*';
            ans[maxR+1][maxC+1] = 'c';
        }
        else if (M/C <= R-2 && M%C == 0) {
            int maxR = M/C;
            ans = vector<string>(R, string(C, '.'));
            REP(r, maxR)
                ans[r] = string(C, '*');
            ans[maxR+1][0] = 'c';
        }
        else if (M/R <= C-2 && M%R == 0) {
            int maxC = M/R;
            ans = vector<string>(R, string(C, '.'));
            REP(c, maxC) REP(r, R)
                ans[r][c] = '*';
            ans[0][maxC+1] = 'c';
        }
        else if (M <= (R-2)*(C-2)) {
            ans = vector<string>(R, string(C, '.'));
            int left = M;
            REP(r, R-2) REP(c, C-2) if (left) {
                ans[r][c] = '*';
                --left;
            }
            ans[R-1][C-1] = 'c';
        }
        else if (canRect(S, recR, recC)) {
            ans = vector<string>(R, string(C, '*'));
            REP(r, recR) REP(c, recC) {
                ans[R-r-1][C-c-1] = '.';
            }
            ans[R-1][C-1] = 'c';
        }
        else if (canKaidan(ansK)) {
            ans = vector<string>(R, string(C, '.'));
            REP(r, R) {
                REP(c, ansK[r]) {
                    ans[r][c] = '*';
                }
            }
            ans[R-1][C-1] = 'c';
        }
        else {
            // ng
        }
    }

    if (swaped) {
        swap(R, C);
        if (!ans.empty()) {
            vector<string> ans_bak = ans;
            ans = vector<string>(R, string(C, '.'));
            REP(r, R) REP(c, C) {
                ans[r][c] = ans_bak[c][r];
            }
        }
    }

    return ans;
}


int main(void)
{
    int T;
    cin >> T;
    REP(_t, T) {
        cout << "Case #" << _t+1 << ":" << endl;
        vector<string> ans = solve();
        if (ans.empty()) {
            cout << "Impossible" << endl;
        } else {
            bool ok = can(ans, true);
            cerr << _t << ": OK=" << ok << endl;
            assert(ok);
            REPV(ans, i) {
                cout << ans[i] << endl;
            }
        }
    }

    return 0;
}

