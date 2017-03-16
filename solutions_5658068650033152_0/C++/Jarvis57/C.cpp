#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

int f[22][22][444];

void load() {
    fstream fin; fin.open("C.txt", fstream :: in);
    int m, n, k;
    while (fin >> m >> n >> k) {
        fin >> f[m][n][k];
    }
    fin.close();
}

int main() {
    ios :: sync_with_stdio(false);
    load();
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        int m, n, k;
        cin >> m >> n >> k;
        int res = f[m][n][k];
        FOR(x,k,m*n) res = min(res, f[m][n][x]);
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
