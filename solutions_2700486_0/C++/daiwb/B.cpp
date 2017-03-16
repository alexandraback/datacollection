#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;

int N, X, Y, p, n, idx;
int tt[4] = { 1, 6, 15, 28 };
LL dd[15][15];

void init() {
    FOR(i,1,15) {
        dd[i][0] = dd[i][i] = 1;
        dd[i][1] = i;
    }
    FOR(i,3,15) {
        FOR(j,2,i-1) {
            dd[i][j] = dd[i - 1][j] + dd[i - 1][j - 1];
        }
    }
}

void run() {
    cin >> N >> X  >> Y;
    if (X < 0) X = -X;
    REP(i,4) {
        if (N < tt[i + 1]) {
            idx = i;
            p = i * 2;
            n = N - tt[i];
            break;
        }
    }

    int sum = X + Y;
    if (sum <= p) {
        cout << "1.0" << endl;
        return;
    } else if (sum > p + 2) {
        cout << "0.0" << endl;
        return;
    }

    if (Y == (idx + 1) * 2) {
        cout << "0.0" << endl;
        return;
    }

    if (n == 0) {
        cout << "0.0" << endl;
        return;
    }

    int q = Y + 1, s = (idx + 1) * 2;
    if (q > n) {
        cout << "0.0" << endl;
        return;
    }

    double tmp = 0.0, tot = 0.0;
    FOR(i,0,s) {
        int r = n - i;
        if (r < 0 || r > s) continue;
        tot += dd[n][i];
        if (i >= q) tmp += dd[n][i];
    }
    double res = tmp / tot;
    cout.precision(8);
    cout << res << endl;
}

int main() {
    init();
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
