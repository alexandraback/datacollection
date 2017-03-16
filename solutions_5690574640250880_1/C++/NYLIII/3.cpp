#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; test++) {
        int R, C, M;
        cin >> R >> C >> M;
        char m[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                m[i][j] = '.';
            }
        }
        int row = R, col = C;
        while (M > 0) {
            if (M >= min(row, col)) {
                if (row >= col) {
                    for (int i = 0; i < col; i++) {
                        m[row - 1][i] = '*';
                        M--;
                    }
                    row--;
                } else {
                    for (int i = 0; i < row; i++) {
                        m[i][col - 1] = '*';
                        M--;
                    }
                    col--;
                }
            } else {
                for (int i = row - 1; i > 1 && M > 0 && col > 2; i--, M--) {
                    m[i][col - 1] = '*';
                }
                for (int i = col - 2; i > 1 && M > 0 && row > 2; i--, M--) {
                    m[row - 1][i] = '*';
                }
                if (M > 0) break;
            }
        }
        cout << "Case #" << test << ":" << endl;
        if ((M > 0) || ((row == 1 || col == 1) && (row > 1 || col > 1) && (R > 1 && C > 1))) {
            cout << "Impossible" << endl;
        } else {
            m[0][0] = 'c';
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cout << m[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}



