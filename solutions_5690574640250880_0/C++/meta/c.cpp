#include <iostream>

using namespace std;

int main() {
    int tcc;
    cin >> tcc;
    for (int tc = 1; tc <= tcc; tc++) {
        bool board[100][100] = {}; // [row][column]
        int r, c, m;
        cin >> r >> c >> m;
        int h = r;
        int w = c;
        while (m > 0) {
            if (h < w) {
                if (h > m) break;
                m -= h;
                for (int i = 0; i < h; i++) board[i][w-1] = true;
                w--;
            } else {
                if (w > m) break;
                m -= w;
                for (int i = 0; i < w; i++) board[h - 1][i] = true;
                h--;
            }
        }
        for (int i = h - 1; i > 1 && m > 0; i--) {
            for (int j = w - 1; j > 1 && m > 0; j--) {
                m--;
                board[i][j] = true;
            }
        }
        bool possible = true;
        if (m > 0) {
            possible = false;
        } else {
            int all = 0, filled = 0;
            for (int i = 0; i < 2 && i < r; i++) {
                for (int j = 0; j < 2 && j < c; j++) {
                    all++;
                    if (board[i][j]) filled++;
                }
            }
            possible = (filled == 0) || (filled == all - 1);
        }
        printf("Case #%d:\n", tc);

        if (possible) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i == 0 && j == 0) {
                        cout << "c";
                        continue;
                    }
                    if (board[i][j]) {
                        cout << "*";
                    } else {
                        cout << ".";
                    }
                }
                cout << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
}
