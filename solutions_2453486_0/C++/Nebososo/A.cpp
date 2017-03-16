#include <cstdio>
#include <cstring>

bool deux, deuo, cheio;
int T;
char m[8][8];
int TS = 0;

bool testa(char q){
    int i, n;

    for(i = 0; i < 4; i++){
        for(n = 0; n < 4; n++)
            if(m[i][n] != q && m[i][n] != 'T')
                break;

        if(n == 4)
            return 1;
    }

    for(i = 0; i < 4; i++){
        for(n = 0; n < 4; n++)
            if(m[n][i] != q && m[n][i] != 'T')
                break;

        if(n == 4)
            return 1;
    }

    for(i = 0; i < 4; i++)
        if(m[i][i] != q && m[i][i] != 'T')
            break;
    if(i == 4)
        return 1;

    for(i = 0; i < 4; i++)
        if(m[i][3-i] != q && m[i][3-i] != 'T')
            break;
    if(i == 4)
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
