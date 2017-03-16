#include<cstdio>

int main(){
    char in[4][5];
    int n;

    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);

    scanf("%d", &n);

    for (int k=0; k<n; k++){
        bool over = true, Xwon = false, Owon = false;

        for (int i=0; i<4; i++) scanf("%s", in[i]);

        /* judge for X */
        for (int i=0; i<4; i++){
            bool suc = true;
            for (int j=0; j<4; j++){
                if (in[i][j] != 'X' && in[i][j] != 'T') suc = false;
            }
            if (suc)    Xwon = true;
        }
        for (int i=0; i<4; i++){
            bool suc = true;
            for (int j=0; j<4; j++){
                if (in[j][i] != 'X' && in[j][i] != 'T') suc = false;
            }
            if (suc)    Xwon = true;
        }

        bool succ = true;
        for (int i=0; i<4; i++){
            if (in[i][i] != 'X' && in[i][i] != 'T') succ = false;
        }
        if (succ)    Xwon = true;

        succ = true;
        for (int i=0; i<4; i++){
            if (in[i][3-i] != 'X' && in[i][3-i] != 'T') succ = false;
        }
        if (succ)    Xwon = true;



        /* judge for O */
        for (int i=0; i<4; i++){
            bool suc = true;
            for (int j=0; j<4; j++){
                if (in[i][j] != 'O' && in[i][j] != 'T') suc = false;
            }
            if (suc)    Owon = true;
        }
        for (int i=0; i<4; i++){
            bool suc = true;
            for (int j=0; j<4; j++){
                if (in[j][i] != 'O' && in[j][i] != 'T') suc = false;
            }
            if (suc)    Owon = true;
        }

        succ = true;
        for (int i=0; i<4; i++){
            if (in[i][i] != 'O' && in[i][i] != 'T') succ = false;
        }
        if (succ)    Owon = true;

        succ = true;
        for (int i=0; i<4; i++){
            if (in[i][3-i] != 'O' && in[i][3-i] != 'T') succ = false;
        }
        if (succ)    Owon = true;


        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                if (in[i][j] == '.')    over = false;
            }
        }

        printf("Case #%d: ", k+1);
        if (Xwon)   puts("X won");
        else if (Owon)  puts("O won");
        else if (over)  puts("Draw");
        else    puts("Game has not completed");
    }
}
