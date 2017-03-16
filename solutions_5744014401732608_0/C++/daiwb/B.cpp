#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

int mat[6][6];
int B, M;

int doit() {
    int a[6] = { 0 };
    FOR(i, 1, B - 1) {
        if (mat[0][i] == 1) a[i] = 1;
    }
    FOR(i, 1, B - 1) {
        FOR(j, i + 1, B - 1) {
            if (mat[i][j] == 1) a[j] += a[i];
        }
    }

    return a[B - 1];
}

void run() {
    cin >> B >> M;
    if (B == 2) {
        if (M == 1) {
            cout << "POSSIBLE" << endl;
            cout << "01" << endl << "00" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
        return;
    }

    memset(mat, 0, sizeof(mat));
    int n = B - 1;
    int tot = (n + 1) * n / 2;
    int all = (1 << tot);
    REP(st, all) {
        memset(mat, 0, sizeof(mat));
        int idx = 0;
        FOR(i, 0, B - 2) {
            FOR(j, i + 1, B - 1) {
                if (st & (1 << idx)) {
                    mat[i][j] = 1;
                }
                ++idx;
            }
        }
        int t = doit();
        if (t == M) {
            cout << "POSSIBLE" << endl;
            REP(i, B) {
                REP(j, B) {
                    cout << mat[i][j];
                }
                cout << endl;
            }
            return;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
