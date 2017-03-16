#include <cstdio>

#define N_ROW 4

int T;
char g[10][10];
int nDot, nX, nO;
bool fAns;

void cWin() {
    if (fAns) return;
    if (nX == N_ROW) {
        fAns = true;
        printf ("X won\n");
        return;
    }
    if (nO == N_ROW) {
        fAns = true;
        printf ("O won\n");
        return;
    }
    nX = nO = 0;
    return;
}

int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf (" %d ", &T);
    for (int _t = 1; _t <= T; _t++) {
        printf ("Case #%d: ", _t);
        nX = nO = nDot = 0;
        fAns = false;
        for (int i = 1; i <= N_ROW; i++) {
            for (int p = 1; p <= N_ROW; p++) {
                scanf (" %c ", &g[i][p]);
                nDot += (g[i][p]=='.');
            }
        }
        //Test Diagonals:
        for (int i = 1; i <= N_ROW; i++) {
            nX += (g[i][i]=='X' || g[i][i]=='T');
            nO += (g[i][i]=='O' || g[i][i]=='T');
        }
        cWin();
        for (int i = 1; i <= N_ROW; i++) {
            nX += (g[i][N_ROW-i+1]=='X' || g[i][N_ROW-i+1]=='T');
            nO += (g[i][N_ROW-i+1]=='O' || g[i][N_ROW-i+1]=='T');
        }
        cWin();
        for (int i = 1; i <= N_ROW; i++) {
            for (int p = 1; p <= N_ROW; p++) {
                nX += (g[i][p]=='X' || g[i][p]=='T');
                nO += (g[i][p]=='O' || g[i][p]=='T');
            }
            cWin();
            for (int p = 1; p <= N_ROW; p++) {
                nX += (g[p][i]=='X' || g[p][i]=='T');
                nO += (g[p][i]=='O' || g[p][i]=='T');
            }
            cWin();
        }
        if (!fAns) {
            if (nDot) {
                printf ("Game has not completed\n");
            } else {
                printf ("Draw\n");
            }
        }
    }
    return 0;
}
            
