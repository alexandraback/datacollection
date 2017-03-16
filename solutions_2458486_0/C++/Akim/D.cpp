#include <cstdio>
using namespace std;
#include <vector>
#include <iostream>

vector<int> keys, openers;
vector<vector<int> > inside;
int k, n;
bool used[1 << 22];
int ans[1 << 22];


int Doit(int mask, bool verbose) {
    if (mask == (1 << n) - 1) {
        return 0;
    }
    if (!used[mask]) {
        used[mask] = true;
        ans[mask] = -1;
        for (int i = 0; i < n; ++i) if ((mask & (1 << i)) == 0) {
            int t = openers[i];
            int cnt = 0;
            for (int q = 0; q < (int)keys.size(); ++q) if (keys[q] == t) ++cnt;
            for (int j = 0; j < n; ++j) if (mask & (1 << j)) for (int y = 0; y < (int)inside[j].size(); ++y)
                if (inside[j][y] == t) ++cnt;
            for (int j = 0; j < n; ++j) if (mask & (1 << j)) if (openers[j] == t) --cnt;
            if (cnt < 0) cerr << "BUG" << endl;
            if (cnt == 0) continue;
            if (Doit(mask | (1 << i), false) != -1) {
                ans[mask] = i;
                break;
            }
        }
    }
    if (verbose) {
        if (ans[mask] == -1) cout << " IMPOSSIBLE"; else {
            cout << " " << (ans[mask] + 1);
            Doit(mask | (1 << ans[mask]), true);
        }
    }
    return ans[mask];

}

void solve(int t) {
    cerr << t << endl;
    cin >> k >> n;
    keys.resize(k);
    for (int i = 0; i < k; ++i) cin >> keys[i];
    openers.resize(n);
    inside.resize(n);
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> openers[i] >> y;
        inside[i].resize(y);
        for (int j = 0; j < y; ++j) cin >> inside[i][j];
    }
    for (int i = 0; i < (1 << n); ++i) {
        used[i] = false;
        ans[i] = -1;
    }
    cout << "Case #" << t << ":";
    Doit(0, true);
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve(i + 1);
    return 0;
}

