#include <stdio.h>

int board[5][5];

int i,j;
int cas, T;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("ans.txt","w", stdout);
    scanf("%d\n", &T);

    char ch;
    bool flag;
    for(cas=1; cas <=T; cas++){
        flag = false;
        for(i=0; i<4; i++){
            for(j=0; j<4; j++){
                scanf("%c", &ch);
                board[i][j] = 0;
                if (ch == 'T') board[i][j] = 3;
                if (ch == 'X') board[i][j] = 1;
                if (ch == 'O') board[i][j] = 2;
                if (board[i][j] == 0) flag = true;
            }
            scanf("\n\n");
        }

        int res, ans = 0;
        for(i=0; i<4; i++){
            res = board[i][0];
            for(j=1; j<4; j++) res &= board[i][j];
            if (res != 0){
                ans = res;
                break;
            }

            res = board[0][i];
            for(j=1; j<4; j++) res &= board[j][i];
            if (res != 0){
                ans = res;
                break;
            }
        }

        if (ans == 0){
            res = board[0][0];
            for(i=1; i<4; i++) res &= board[i][i];
            if (res != 0) ans = res;
        }

         if (ans == 0){
            res = board[0][3];
            for(i=1; i<4; i++) res &= board[i][3-i];
            if (res != 0) ans = res;
        }

        printf("Case #%d: ", cas);
        if (res != 0){
            if (res == 1) printf("X won\n");
            if (res == 2) printf("O won\n");
        } else {
            if (flag) printf("Game has not completed\n");
            else printf("Draw\n");
        }

    }



    return 0;
}
