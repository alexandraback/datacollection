#include <iostream>
#include <string>
#include <cstdio>

#define FILENAME "C-small-attempt0"

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

    // small
    for (int i = 1; i < X; ++i) {
        int offset = i * n;
        for (int j = 0; j < n; ++j) {
            ss[offset + j] = ss[j];
        }
    }
    n = X * n;

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
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (sub[0][i] == 1 && sub[i][j] == 2 && sub[j][n] == 3)
                return "YES";
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
