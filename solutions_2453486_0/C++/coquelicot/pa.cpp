#include <cstdio>

int main(){

    int t;
    scanf("%d" ,&t);

    char buf[4][5];

    for(int T = 1; T <= t; T++){

        gets(buf[0]);
        for(int i = 0; i < 4; i++){
            gets(buf[i]);
        }

        int sta = 0, emp = 0;
        for(int i = 0; i < 4 && sta == 0; i++){

            int cx = 0, co = 0;
            for(int j = 0; j < 4; j++){
                if(buf[i][j] == 'X') cx++;
                else if(buf[i][j] == 'O') co++;
                else if(buf[i][j] == 'T') cx++, co++;
                else emp = 1;
            }

            if(cx == 4) sta = 1;
            else if(co == 4) sta = 2;

            cx = 0, co = 0;
            for(int j = 0; j < 4; j++){
                if(buf[j][i] == 'X') cx++;
                else if(buf[j][i] == 'O') co++;
                else if(buf[j][i] == 'T') cx++, co++;
                else emp = 1;
            }

            if(cx == 4) sta = 1;
            else if(co == 4) sta = 2;

        }

        int cx = 0, co = 0;
        for(int i = 0; i < 4; i++){
            if(buf[i][i] == 'X') cx++;
            else if(buf[i][i] == 'O') co++;
            else if(buf[i][i] == 'T') cx++, co++;
            else emp = 1;
        }
        if(cx == 4) sta = 1;
        else if(co == 4) sta = 2;

        cx = 0, co = 0;
        for(int i = 0; i < 4; i++){
            if(buf[i][3-i] == 'X') cx++;
            else if(buf[i][3-i] == 'O') co++;
            else if(buf[i][3-i] == 'T') cx++, co++;
            else emp = 1;
        }
        if(cx == 4) sta = 1;
        else if(co == 4) sta = 2;

        printf("Case #%d: " ,T);
        if(sta == 1) puts("X won");
        else if(sta == 2) puts("O won");
        else if(emp == 1) puts("Game has not completed");
        else puts("Draw");

    }

}
