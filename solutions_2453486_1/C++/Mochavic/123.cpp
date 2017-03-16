#include <stdio.h>
char c[10][10];
int pd(){
    int i, j;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (c[i][j] != 'X' && c[i][j] != 'T') break;
        }
        if (j == 4) return 0;
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (c[j][i] != 'X' && c[j][i] != 'T') break;
        }
        if (j == 4) return 0;
    }
    for (i = 0; i < 4; i++){
        if (c[i][i] != 'X' && c[i][i] != 'T') break;
    }
    if (i == 4) return 0;
    for (i = 0; i < 4; i++){
        if (c[i][3 - i] != 'X' && c[i][3 - i] != 'T') break;
    }
    if (i == 4) return 0;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (c[i][j] != 'O' && c[i][j] != 'T') break;
        }
        if (j == 4) return 1;
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (c[j][i] != 'O' && c[j][i] != 'T') break;
        }
        if (j == 4) return 1;
    }
    for (i = 0; i < 4; i++){
        if (c[i][i] != 'O' && c[i][i] != 'T') break;
    }
    if (i == 4) return 1;
    for (i = 0; i < 4; i++){
        if (c[i][3 - i] != 'O' && c[i][3 - i] != 'T') break;
    }
    if (i == 4) return 1;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
            if (c[i][j] == '.') return 3;
        }
    }
    return 2;
}
int main(){
    int T, ri = 1, i;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        for (i = 0; i < 4; i++) scanf("%s", c[i]);
        printf("Case #%d: ", ri++);
        if (pd() == 0) printf("X won\n");
        else if (pd() == 1) printf("O won\n");
        else if (pd() == 2) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
