#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char field[60][60];
int  numbomb;
int R, C, M;

void clr3x3(int x, int y)
{
    int l = max(x-1, 0);
    int t = max(y-1, 0);
    int r = min(x+1, C-1);
    int b = min(y+1, R-1);

    for (int i = t; i <= b; i++) {
        for (int j = l; j <= r; j++) {
            if (field[i][j] == '*') {
                field[i][j] = '.';
                numbomb--;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> R >> C >> M;

        for (int j = 0; j < R; j++) {
            memset(field[j], '*', C);
            field[j][C] = 0;
        }

        numbomb = R*C;
        int x = 0;
        int y = 0;

        if (M != numbomb - 1 && M != 0) {
            for (int j = 0; j < R; j++) {
                clr3x3(0, j);
                if (numbomb <= M)
                    break;
                clr3x3(0, j+1);
                if (numbomb <= M)
                    break;
                for (int k = 1; k < C; k++) {
                    clr3x3(k, j);
                    if (numbomb <= M)
                        break;
                    if (numbomb - M == 1 && j < R-2)
                        break;
                }
                if (numbomb <= M)
                    break;
                if (numbomb - M == 1 && j < R-2) {
                    clr3x3(1, j+1);
                    // single column fix
                    if (numbomb - M == 1) {
                        clr3x3(1, j+2);
                    }
                    break;
                }
            }
        } else {
            if (M == 0) {
                for (int j = 0; j < R; j++)
                    memset(field[j], '.', C);
            }
            numbomb = M;
        }

        field[0][0] = 'c';
        cout << "Case #" << i << ":" << endl;
        if (numbomb == M) {
            for (int k = 0; k < R; k++) {
                cout << field[k] << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
