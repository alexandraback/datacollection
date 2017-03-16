#include <iostream>
#include <string>
#include <cstdio>

#define FILENAME "C-large"

using namespace std;

// 0, 1, 2, 3,  4,  5,  6,  7
// 1, i, j, k, -1, -i, -j, -k
int M[][8] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

void init() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i >= 4 && j >= 4) {
                M[i][j] = M[i-4][j-4];
            } else if (i >= 4 || j >= 4) {
                M[i][j] = (M[i % 4][j % 4] + 4) % 8;
            }
            //cerr << M[i][j] << ' ';
        }
        //cerr << endl;
    }
}

int sub[10240][10240], ss[10240];

string solveC(long long X, string& S) {
    int n = S.size();
    for (int i = 0; i < n; ++i) {
        ss[i] = (S[i] == 'i' ? 1 : (S[i] == 'j'? 2 : 3));
    }

    for (int i = 0; i < n; ++i) {
        int m;
        sub[i][i] = m = 0;
        //cerr << i << ": 0 ";
        for (int j = i + 1; j <= n; ++j) {
            sub[i][j] = m = M[m][ss[j-1]];
            //cerr << m << " ";
        }
        //cerr << endl;
    }
    sub[n][n] = 0;

    int all[4];
    all[0] = 0;
    all[1] = sub[0][n];
    all[2] = M[all[1]][all[1]];
    all[3] = M[all[2]][all[1]];
    // same segment
    for (int l = 0; l < 4 && l < X; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[all[l]][sub[0][i]] == 1 &&
                    sub[i][j] == 2 &&
                    M[sub[j][n]][all[(X-l-1)%4]] == 3
                ) {
                    return "YES";
                }
            }
        }
    }
    // diff segments
    for (int i1 = 0; i1 < 4 && i1 < X; ++i1) {
        for (int i = 0; i < n; ++i) {
            if (M[all[i1]][sub[0][i]] == 1) {
                for (int j1 = 0; j1 < 4 && (i1 + 1 + j1) < X; ++j1) {
                    int a = M[sub[i][n]][all[j1]],
                        c = all[(X-i1-j1-2) % 4];
                    for (int j = 0; j < n; ++j) {
                        if (M[a][sub[0][j]] == 2 &&
                            M[sub[j][n]][c] == 3
                        ) {
                            return "YES";
                        }
                    }
                }
            }
        }
    }
    return "NO";
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    init();

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long l, x;
        string s;
        cin >> l >> x >> s;
        cout << "Case #" << t << ": " << solveC(x, s) << endl;
        cerr << "Case #" << t << ": solved" << endl;
    }
    return 0;
}
