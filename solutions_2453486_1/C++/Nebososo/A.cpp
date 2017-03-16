#include <cstdio>
#include <cstring>

bool deux, deuo, cheio;
int T;
char m[8][8];
int TS = 0;

bool testa(char q){
    int i, n;
    int t, tt;

    for(i = 0; i < 4; i++){
        t = tt = 0;
        for(n = 0; n < 4; n++)
            if(m[i][n] == q)
                t++;
            else if(m[i][n] == 'T')
                tt++;

        if(tt <= 1 && t + tt == 4)
            return 1;
    }

    for(i = 0; i < 4; i++){
        t = tt = 0;
        for(n = 0; n < 4; n++)
            if(m[n][i] == q)
                t++;
            else if(m[n][i] == 'T')
                tt++;

        if(tt <= 1 && t + tt == 4)
            return 1;
    }

    t = tt = 0;
    for(i = 0; i < 4; i++)
        if(m[i][i] == q)
            t++;
        else if(m[i][i] == 'T')
            tt++;
    if(tt <= 1 && t + tt == 4)
        return 1;

    t = tt = 0;
    for(i = 0; i < 4; i++)
        if(m[i][3-i] == q)
            t++;
        else if(m[i][3-i] == 'T')
            tt++;
    if(tt <= 1 && t + tt == 4)
        return 1;

    return 0;
}

int main(){
    int i, n;

    for(scanf("%d", &T); T--;){
        for(i = 0; i < 4; i++)
            scanf("%s", m[i]);
        printf("Case #%d: ", ++TS);

        deux = testa('X');
        deuo = testa('O');

        cheio = 1;
        for(i = 0; i < 4; i++)
            for(n = 0; n < 4; n++)
                cheio &= (m[i][n] != '.');

        if(deux)
            printf("X won\n");
        else if(deuo)
            printf("O won\n");
        else if(cheio)
            printf("Draw\n");
        else
            printf("Game has not completed\n");
    }

    return 0;
}
