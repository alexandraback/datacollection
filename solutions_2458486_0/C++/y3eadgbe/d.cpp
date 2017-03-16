#include <iostream>
#include <vector>
#include <string>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int keys[1<<20][205];
bool vis[1<<20];
bool dp[1<<20];
int trace[1<<20];
vector<int> need;
int n;

bool recur(int v, int t) {
    if (v == t)return true;
    if (vis[v])return dp[v];
    vis[v] = true;

    bool ans = false;
    rep(i, n) {
        if (!(v & (1 << i))) {
            int nv = v ^ (1 << i);
            if ((keys[v][need[i]] >= 1) && recur(nv, t)) {
                ans = true;
                trace[v] = min(trace[v], i);
                break;
            }
        }
    }
    return (dp[v] = ans);
}

void solve() {
    int key;
    cin >> key >> n;
    rep(i, 1 << n) {
        dp[i] = false;
        vis[i] = false;
        trace[i] = 300;
    }
    need = vector<int>(n);
    rep(i, 1 << n) {
        rep(j, 205)keys[i][j] = 0;
    }
    rep(i, key) {
        int tmp;
        cin >> tmp;
        keys[0][tmp]++;
    }

    rep(i, n) {
        int num;
        cin >> need[i] >> num;
        keys[1 << i][need[i]]--;
        rep(j, num) {
            int tmp;
            cin >> tmp;
            keys[1 << i][tmp]++;
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) <= 1) continue;
        rep(j, n) {
            if (i & (1 << j)) {
                rep(k, 205) {
                    keys[i][k] += keys[i & (1 << j)][k];
                }
            }
        }
    }

    for (int i = 1; i < (1 << n); i++) {
        rep(k, 205) {
            keys[i][k] += keys[0][k];
        }
    }
    
    if (recur(0, (1 << n) - 1)) {
        vector<int> ans(n);
        int mask = 0;
        rep(i, n) {
            ans[i] = trace[mask];
            mask |= 1 << trace[mask];
        }
        rep(i, n) {
            if (i)cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl;
        return;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i,T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
