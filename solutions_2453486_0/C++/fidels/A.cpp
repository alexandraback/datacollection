#include <iostream>
#include <cassert>
using namespace std;

int main() {
    int i, j, tmp, RES, t, T;
    char m[4][4];

    cin >> T;
    for (t=1; t<=T; t++) {
        for (i=0; i<4; i++) for (j=0; j<4; j++) cin >> m[i][j];
    
        RES = -1;
        for (i=0; i<4; i++) {
            tmp = 0;
            for (j=0; j<4; j++) tmp += m[i][j];
            if (tmp == 4*'X' || tmp == 3*'X' + 'T') RES = 0;
            else if (tmp == 4*'O' || tmp == 3*'O' + 'T') RES = 1;
    
            tmp = 0;
            for (j=0; j<4; j++) tmp += m[j][i];
            if (tmp == 4*'X' || tmp == 3*'X' + 'T') RES = 0;
            else if (tmp == 4*'O' || tmp == 3*'O' + 'T') RES = 1;
        }
    
        tmp = 0;
        for (i=0; i<4; i++) tmp += m[i][i];
        if (tmp == 4*'X' || tmp == 3*'X' + 'T') RES = 0;
        else if (tmp == 4*'O' || tmp == 3*'O' + 'T') RES = 1;
    
        tmp = 0;
        for (i=0; i<4; i++) tmp += m[3-i][i];
        if (tmp == 4*'X' || tmp == 3*'X' + 'T') RES = 0;
        else if (tmp == 4*'O' || tmp == 3*'O' + 'T') RES = 1;
    
        if (RES == -1) {
            RES = 2;
            for (i=0; i<4; i++) for (j=0; j<4; j++) if (m[i][j] == '.') RES = 3;
        }

        cout << "Case #" << t << ": ";
        if (RES == 0) cout << "X won" << endl;
        else if (RES == 1) cout << "O won" << endl;
        else if (RES == 2) cout << "Draw" << endl;
        else if (RES == 3) cout << "Game has not completed" << endl;
        else assert(false);
    }

    return 0;
}
