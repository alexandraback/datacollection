#include <iostream>
#include <vector>
#include <queue>


using namespace std;

bool check(int b, int m, vector<vector<bool>> &g) {
    vector<int> d(b);
    d[0] = 1;
    for (int i = 0; i < b; ++i) {
        for (int j = i + 1; j < b; ++j) {
            if (g[i][j]) {
                d[j] += d[i];
            }
        }
    }
    return d[b - 1] == m;
}

bool gen(int b, int m, vector<vector<bool>> &g, int i, int j) {
    if (i == b - 1) {
        if (check(b, m, g)) {
            return true;
        }
        return false;
    } else {
        int ni = i + (j + 1 == b);
        int nj = (j + 1 == b) ? ni + 1 : j + 1;
        g[i][j] = false;
        if (gen(b, m, g, ni, nj)) {
            return true;
        }
        g[i][j] = true;
        return gen(b, m, g, ni, nj);
    }
}

int main() {
    int tn;
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        cout << "Case #" << ti << ": ";
        int b, m;
        cin >> b >> m;
        vector<vector<bool>> g(b, vector<bool>(b));
        if (gen(b, m, g, 0, 1)) {
            cout << "POSSIBLE\n";
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) {
                    cout << g[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    cout << flush;

    return 0;
}
