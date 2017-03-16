
#include <cassert>
#include <iostream>
#include <vector>
#define MAXN 50

using namespace std;

int n;
int a[2 * MAXN][MAXN];
int g[MAXN][MAXN];
bool used[2 * MAXN];
vector <int> cand[MAXN];
int missing;

bool can_place_row(int k, int i) {
    if (k == 0)
        return true;
    for (int j = k; j < n; j++)
        if (a[i][j] <= g[k - 1][j])
            return false;
    for (int j = 0; j < k; j++)
        if (a[i][j] != g[k][j] && g[k][j] != 0)
            return false;
    for (int j = 0; j < n; j++) {
        bool found = false;
        for (int l : cand[j]) {
            bool eq = true;
            for (int m = 0; m < k; m++)
                if (a[l][m] != g[j][m] && g[j][m] != 0) {
                    eq = false;
                    break;
                }
            if (eq) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

bool can_place_col(int k, int i) {
    if (k == 0)
        return true;
    for (int j = k; j < n; j++)
        if (a[i][j] <= g[j][k - 1])
            return false;
    for (int j = 0; j < k; j++)
        if (a[i][j] != g[j][k] && g[j][k] != 0)
            return false;
    return true;
}

void set_row(int k, int i) {
    for (int j = k; j < n; j++)
        g[k][j] = a[i][j];
    g[k][missing] = a[i][missing];
}

void set_col(int k, int i) {
    for (int j = k; j < n; j++)
        g[j][k] = a[i][j];
    g[missing][k] = a[i][missing];
}

bool solve(int k) {
    if (k == n)
        return true;

    if (cand[k].size() == 1) {
        int i = cand[k][0];
        if (can_place_row(k, i)) {
            set_row(k, i);
            if (solve(k + 1))
                return true;
            for (int j = k; j < n; j++)
                g[k][j] = g[j][k] = 0;
        }
        if (can_place_col(k, i)) {
            set_col(k, i);
            if (solve(k + 1))
                return true;
            for (int j = k; j < n; j++)
                g[k][j] = g[j][k] = 0;
        }
        return false;
    }

    assert(cand[k].size() == 2);

    int i = cand[k][0], j = cand[k][1];
    if (can_place_row(k, j) && can_place_col(k, i)) {
        set_row(k, j);
        set_col(k, i);
        if (solve(k + 1))
            return true;
        for (int l = k; l < n; l++)
            g[k][l] = g[l][k] = 0;
    }
    if (can_place_row(k, i) && can_place_col(k, j)) {
        set_row(k, i);
        set_col(k, j);
        if (solve(k + 1))
            return true;
        for (int l = k; l < n; l++)
            g[k][l] = g[l][k] = 0;
    }
    return false;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            g[i][j] = 0;
        cand[i].clear();
    }
    for (int i = 0; i < 2 * n - 1; i++)
        used[i] = false;

    for (int k = 0; k < n; k++) {
        int minval = 3000;
        for (int i = 0; i < 2 * n - 1; i++) {
            if (used[i])
                continue;
            if (a[i][k] < minval) {
                minval = a[i][k];
                cand[k].clear();
            }
            if (a[i][k] == minval)
                cand[k].push_back(i);
        }
        if (cand[k].size() == 1)
            missing = k;
        for (int i : cand[k])
            used[i] = true;
        // cerr << "CAND " << cand[k].size() << endl;
    }

    solve(0);

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
    */

    int k = missing;
    int i = cand[k][0];
    bool eq = true;
    for (int j = 0; j < n; j++)
        if (a[i][j] != g[k][j]) {
            eq = false;
            break;
        }
    if (!eq) {
        for (int j = 0; j < n; j++)
            cout << " " << g[k][j];
    }
    else {
        for (int j = 0; j < n; j++)
            cout << " " << g[j][k];
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < 2 * n - 1; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        cout << "Case #" << t << ":";
        solve();
    }
}
