#include <cstdio>

using namespace std;
int T;
int matriz[4][4];
int resp[10];

void actualizar (int row, int col, int am) {
    /*if (am == 2) {
        resp[row] += (resp[row] < 0 ? -1 : 1);
        resp[col+4] += (resp[col+4] < 0 ? -1 : 1);
        if (row == col) resp[8] += (resp[8] < 0 ? -1 : 1);
        else {
            if (row + col == 3) {
                resp[9] += (resp[9] < 0 ? -1 : 1);
            }
        }
    } else {*/
        resp[row] += am;
        resp[col+4] += am;
        if (row == col) resp[8] += am;
        else {
            if (row + col == 3) {
                resp[9] += am;
            }
        }
    //}
}

main () {
    char line[5];
    bool listo = true, gano;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        printf("Case #%d: ", i+1);
        listo = true;
        gano = false;
        for (int j = 0; j < 4; j++) {
            scanf("%s", line);
            for (int k = 0; k < 4; k++) {
                if (line[k] == 'X') {
                    actualizar(j, k, 1);
                } else if (line[k] == 'O') {
                   actualizar(j, k, 5);
                } else if (line[k] == 'T') {
                    actualizar(j, k, 25);
                } else {
                    listo = false;
                    matriz[j][k] = 0;
                }
            }
        }
        /*for (int j = 0; j < 10; j++) {
            printf("%d ", resp[j]);
        }
        printf("\n");*/
        for (int j = 0; j < 10; j++) {
            if ((resp[j] == 4 || resp[j] == 28) && !gano) {
                gano = true;
                printf("X won\n");
            } else if ((resp[j] == 20 || resp[j] == 40) && !gano) {
                printf("O won\n");
                gano = true;
            }
            resp[j] = 0;
        }
        if (listo && !gano) printf("Draw\n");
        else if (!listo && !gano) printf("Game has not completed\n");
    }
}
