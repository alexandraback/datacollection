#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

int cache[22][22][444];
vector< vector< vector<int> > > f;

void update(int &x, int val) {
    x = max(x, val);
}

int guess(int m, int n, int k) {
    if (k < 4) return k;
    int gh = 2*m + 2*n - 4;

    f.resize(m + 5);
    REP(i,f.size()) {
        f[i].resize(n+5);
        REP(j,f[i].size()) {
            f[i][j].resize(gh+5);
            REP(x,f[i][j].size()) f[i][j][x] = -1000111000;
        }
    }

    FOR(x,0,n) f[1][x][x] = x;

    FOR(nrow,1,m-1) FOR(open,1,n) FOR(used,1,gh) {
        // Add new row
        FOR(t,-2,2) {
            if (open+t >= 0 && open+t <= n && used+2 <= gh) {
                update(f[nrow+1][open+t][used+2], f[nrow][open][used] + open+t);
            }
        }
        // Close them
        FOR(t,0,2)
        if (open >= t && used+open-t <= gh) {
            update(f[nrow+1][0][used+open-t], f[nrow][open][used] + open-t);
        }
    }

    int res = min(k, gh);
    FOR(nrow,1,m) FOR(used,0,gh)
        if (f[nrow][0][used] >= k) {
            res = min(res, used);
        }
    return res;
}

void load() {
    fstream fin; fin.open("C.txt", fstream :: in);
    int m, n, k;
    while (fin >> m >> n >> k) {
        fin >> cache[m][n][k];
    }
    FOR(m,1,20) FOR(n,1,20) if (m*n <= 20) {
        FOR(k,0,m*n) {
            int res = cache[m][n][k];
            FOR(x,k,m*n) res = min(res, cache[m][n][x]);
            if (res != guess(m, n, k)) {
                cout << m << ' ' << n << ' ' << k << ' ' << res << ' ' << guess(m, n, k) << endl;
            }
        }
    }
    fin.close();
}

int main() {
    ios :: sync_with_stdio(false);
    // load();
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        int m, n, k;
        cin >> m >> n >> k;
        cout << "Case #" << test << ": " << guess(m, n, k) << endl;
        cerr << test << endl;
    }
    return 0;
}
