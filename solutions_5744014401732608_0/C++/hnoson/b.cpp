#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RREP(i,s,e) for (i = s; i >= e; i--)
#define rrep(i,n) RREP(i,(int)(n)-1,0)
#define REP(i,s,e) for (i = s; i <= e; i++)
#define rep(i,n) REP(i,0,(int)(n)-1)
#define INF 100000000

typedef long long ll;

bool pass[51][51]; // way i to j

ll pow(ll x, int n) {
    ll ret = 1;
    while (n > 0) {
        if (n % 2)
            ret += x;
        x *= x;
        n /= 2;
    }
    return ret;
}

void solve(int test) {
    int i, j, b;
    ll m;
    cin >> b >> m;

    REP (i,1,b) REP (j,1,b) pass[i][j] = false;
    REP (i,2,b-1) REP (j,i+1,b) pass[i][j] = true;

    cout << "Case #" << test << ": ";
    if (m > pow(2,b-2)) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << "POSSIBLE" << endl;
        if (m == pow(2,b-2)) {
            m--;
            pass[1][b] = true;
        }
        for (i = b-1; i > 1; i--) {
            if (m % 2) {
                pass[1][i] = true;
            }
            m /= 2;
        }
        REP (i,1,b) {
            REP (j,1,b)
                cout << pass[i][j];
            cout << endl;
        }
    }
}

int main() {
    int i, t;
    cin >> t;
    rep (i,t) solve(i+1);
    return 0;
}

