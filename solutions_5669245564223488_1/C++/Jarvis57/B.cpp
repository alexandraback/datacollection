#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
using namespace std;

const int MOD = 1000000007;
const int MN = 111;

string a[MN];
long long gt[MN];
int n;

bool check() {
    // ...X...Y...X...
    FOR(i,1,n) {
        REP(x,a[i].length())
        FOR(y,x+1,a[i].length()-1)
        FOR(z,y+1,a[i].length()-1)
            if (a[i][x] == a[i][z] && a[i][x] != a[i][y]) return false;
    }
    // ...X...
    // ...X...
    FOR(i,1,n) FOR(j,1,n) if (i != j) {
        REP(x,a[i].length())
        FOR(y,1,a[j].length()-2)
        if (a[j][y] != a[j][0] && a[j][y] != a[j][a[j].length()-1])
            if (a[i][x] == a[j][y]) return false;
    }
    // X....
    // X....
    FOR(i,1,n) FOR(j,1,n) if (i != j) {
        if (a[i][0] != a[i][a[i].length()-1] && a[j][0] != a[j][a[j].length()-1]) {
            if (a[i][0] == a[j][0]) return false;
            if (a[i][a[i].length()-1] == a[j][a[j].length()-1]) return false;
        }
    }
    return true;
}

int allx[300];
bool used[MN];

vector<int> ke[MN];
int visited[MN];

bool hasCycle() {
    FOR(i,1,n) if (!used[i] && ke[i].size() > 1) return true;

    FOR(i,1,n) if (!visited[i] && !used[i]) {
        int u = i;
        visited[u] = u;
        while (ke[u].size() == 1) {
            int v = ke[u][0];
            if (visited[v] == visited[u]) return true;
            visited[v] = visited[u];
            u = v;
        }
    }
    return false;
}

int main() {
    gt[0] = 1; FOR(i,1,100) gt[i] = (gt[i-1] * i) % MOD;

    ios :: sync_with_stdio(false);
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        cout << "Case #" << test << ": ";
        if (!check()) cout << 0 << endl;
        else {
            memset(allx, 0, sizeof allx);
            memset(used, false, sizeof used);
            FOR(i,1,n) if (a[i][0] == a[i][a[i].length()-1]) {
                ++allx[a[i][0]];
                used[i] = true;
            }

            FOR(i,1,n) ke[i].clear();
            memset(visited, false, sizeof visited);

            FOR(i,1,n) FOR(j,1,n) if (i != j && !used[i] && !used[j]) {
                if (a[i][0] == a[j][a[j].length()-1]) {
                    ke[j].push_back(i);
                }
            }
            if (hasCycle()) {
                cout << 0 << endl;
                continue;
            }

            vector<long long> f;
            FOR(i,1,n) if (!used[i]) {
                char x = a[i][0], y = a[i][a[i].length()-1];
                long long cur = 1;
                used[i] = true;

                // DEBUG(i);

                bool added = true;
                while (added) {
                    // DEBUG(x);
                    // DEBUG(y);
                    if (allx[x]) cur = (cur * gt[allx[x]]) % MOD, allx[x] = 0;
                    if (allx[y]) cur = (cur * gt[allx[y]]) % MOD, allx[y] = 0;

                    added = false;
                    FOR(j,1,n) if (!used[j]) {
                        if (a[j][0] == y) {
                            y = a[j][a[j].length()-1];
                            used[j] = true;
                            added = true;
                            break;
                        }
                        else if (a[j][a[j].length()-1] == x) {
                            x = a[j][0];
                            used[j] = true;
                            added = true;
                            break;
                        }
                    }
                }
                // DEBUG(cur);
                f.push_back(cur);
            }

            FOR(c,'a','z') if (allx[c]) {
                f.push_back(gt[allx[c]]);
            }

            long long res = gt[f.size()];
            REP(i,f.size())
                res = (res * f[i]) % MOD;

            cout << res << endl;
        }
    }
    return 0;
}
