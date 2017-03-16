#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 55

int T, R, C, M;
int A[MAXN][MAXN];
bool ok;
bool v[MAXN][MAXN];

int di[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dj[] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int zLeft;
void dfs(int pi, int pj) {
    v[pi][pj] = true;
    zLeft--;
    bool one = false;
    for(int d = 0; d < 8 && !one; d++) {
        int ni = pi + di[d];
        int nj = pj + dj[d];
        if(ni >= 0 && ni < R && nj >= 0 && nj < C && A[ni][nj] == 1) {
            one = true;
        }
    }
    if(one)
        return;
    
    for(int d = 0; d < 8 && !one; d++) {
        int ni = pi + di[d];
        int nj = pj + dj[d];
        if(ni >= 0 && ni < R && nj >= 0 && nj < C && A[ni][nj] == 0 && !v[ni][nj]) {
            dfs(ni, nj);
        }
    }
}

bool pathCheck(int pi, int pj) {
    zLeft = R * C - M;
    memset(v, false, sizeof(v));
    dfs(pi, pj);
    return zLeft == 0;
}

bool check() {
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(A[i][j] == 0) {
                bool valid = true;
                if(M < R * C - 1) {
                    for(int d = 0; d < 8 && valid; d++) {
                        int ni = i + di[d];
                        int nj = j + dj[d];
                        if(ni >= 0 && ni < R && nj >= 0 && nj < C && A[ni][nj] == 1)
                            valid = false;
                    }
                }
                if(valid && pathCheck(i, j)) {
                    A[i][j] = 2;
                    return true;
                }
            }
    return false;
}

void back(int pi, int pj, int m) {
    if(m == 0) {
        if(check())
            ok = true;
        return;
    }
    if(pi == R)
        return;
    
    for(int t = 1; t >= 0 && !ok; t--) {
        A[pi][pj] = t;
        int ni = pi;
        int nj = pj + 1;
        if(nj >= C) {
            ni++;
            nj = 0;
        }
        back(ni, nj, m - t);
    }
}

bool solve() {
    ok = false;
    memset(A, 0, sizeof(A));
    back(0, 0, M);
    return ok;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	cin >> T;
	for(int t = 1; t <= T; t++) {
        cin >> R >> C >> M;
        
        cout << "Case #" << t << ":\n";
        if(solve()) {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(A[i][j] == 0)
                        cout << '.';
                    else if(A[i][j] == 1)
                        cout << '*';
                    else
                        cout << 'c';
                }
                cout << '\n';
            }
        }
        else {
            cout << "Impossible\n";
        }
        
        cerr << t << '\n';
	}
	
	return 0;
}
