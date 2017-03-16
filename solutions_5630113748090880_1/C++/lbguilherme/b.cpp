#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> strips;
int possib[60][2];

int minAt(vector<bool>& taken, int t) {
    int ans = 99999999;
    for (int i = 0; i < (2 * n - 1); ++i)
        if (!taken[i])
            ans = min(ans, strips[i][t]);
    return ans;
}

void solve() {
    cin >> n;
    strips.clear();
    strips.resize(2 * n - 1);
    vector<bool> taken(2 * n - 1);
    for (int i = 0; i < (2 * n - 1); ++i) {
        strips[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> strips[i][j];
        }
    }

    for (int t = 0; t < n; ++t) {
        int min = minAt(taken, t);
        possib[t][0] = -1;
        possib[t][1] = -1;
        int p = 0;
        for (int i = 0; i < (2 * n - 1); ++i) {
            if (!taken[i] && strips[i][t] == min) {
                taken[i] = true;
                possib[t][p++] = i;
            }
        }
    }

    int ans[n];
    for (int t = 0; t < n; ++t) {
        if (possib[t][1] != -1)
            continue;
        int id = possib[t][0];
        for (int i = 0; i < n; ++i) {
            if (i == t)
                ans[i] = strips[id][i];
            else if (strips[id][i] == strips[possib[i][0]][t])
                ans[i] = strips[possib[i][1]][t];
            else
                ans[i] = strips[possib[i][0]][t];
        }
        break;
    }
    for (int i = 0; i < n; ++i) {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }
}
