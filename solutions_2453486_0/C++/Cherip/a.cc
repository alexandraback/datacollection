#include <stdio.h>

char mat[4][4];

int judge_win(char c) {
    int flag;
    for (int i = 0; i < 4; i++) {
        flag = 1;
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] == c || mat[i][j] == 'T')
                continue;
            flag = 0;
        }

        if (flag) return 1;
        flag = 1;
        for (int j = 0; j < 4; j++) {
            if (mat[j][i] == c || mat[j][i] == 'T')
                continue;
            flag = 0;
        }

        if (flag) return 2;
    }

    flag = 1;
    for (int i = 0; i < 4; i++) {
        if (mat[i][i] != c &&  mat[i][i] != 'T') {
            flag = 0;
            break;
        }
    }
    if (flag) return 3;

    flag = 1;
    for (int i = 0; i < 4; i++) {
        if (mat[i][3 - i] != c &&  mat[i][3 - i] != 'T') {
            flag = 0;
            break;
        }
    }
    if (flag) return 4;

    return 0;
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("result.txt", "w", stdout);
    int t=0;
    scanf("%d", &t);
    int k = 0;
    for (int idx = 1; idx <= t; idx++) {
        k=0;
        for (int i = 0; i < 4; i++){
            scanf("%s", mat[i]);
            //printf("%s\n", mat[i]);
            for (int j =0; j < 4; j++) {
                if (mat[i][j] == '.') k = 1;
                //printf("%c", mat[i][j]);
            }
            //printf("\n");
        }
        printf("Case #%d: ", idx);
        //printf("%d\n", judge_win('X'));
        if (judge_win('X')) {
            printf("X won\n");
        } else if (judge_win('O')) {
            printf("O won\n");
        } else {
            if (k) {
                printf("Game has not completed\n");
            } else
                printf("Draw\n");
        }
    }
}
