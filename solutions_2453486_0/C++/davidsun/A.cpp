#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
char G[10][10], G2[10][10];

char winner(int xCount, int oCount, int tCount){
    if (xCount == 4 || (xCount == 3 && tCount == 1)) return 'X';
    else if (oCount == 4 || (oCount == 3 && tCount == 1)) return 'O';
    else return '-';
}

char judge(){
    for (int i = 0; i < 4; i ++){
        int xCount = 0, oCount = 0, tCount = 0;
        for (int j = 0; j < 4; j ++){
            xCount += (G[i][j] == 'X');
            oCount += (G[i][j] == 'O');
            tCount += (G[i][j] == 'T');
        }
        char w = winner(xCount, oCount, tCount);
        if (w != '-') return w;
    }

    for (int i = 0; i < 4; i ++){
        int xCount = 0, oCount = 0, tCount = 0;
        for (int j = 0; j < 4; j ++){
            xCount += (G[j][i] == 'X');
            oCount += (G[j][i] == 'O');
            tCount += (G[j][i] == 'T');
        }
        char w = winner(xCount, oCount, tCount);
        if (w != '-') return w;
    }
    {
        int xCount = 0, oCount = 0, tCount = 0;
        for (int i = 0; i < 4; i ++){
            xCount += (G[i][i] == 'X');
            oCount += (G[i][i] == 'O');
            tCount += (G[i][i] == 'T');
        }
        char w = winner(xCount, oCount, tCount);
        if (w != '-') return w;
    }

    {
        int xCount = 0, oCount = 0, tCount = 0;
        for (int i = 0; i < 4; i ++){
            xCount += (G[i][3 - i] == 'X');
            oCount += (G[i][3 - i] == 'O');
            tCount += (G[i][3 - i] == 'T');
        }
        char w = winner(xCount, oCount, tCount);
        if (w != '-') return w;
    }

    return '-';
}

int main(void){
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc ++){
        for (int i = 0; i < 4; i ++) scanf("%s", G[i]);
        memcpy(G2, G, sizeof(G));
        char w = judge();
        if (w == 'X'){
            printf("Case #%d: X won\n", tc + 1);
        }  else if (w == 'O'){
            printf("Case #%d: O won\n", tc + 1);
        }  else {
            int found = 0;
            for (int i = 0; i < 4; i ++)
                for (int j = 0; j < 4; j ++)
                    if (G[i][j] == '.') G[i][j] = 'X';
            if (judge() != '-') found = 1;
            memcpy(G, G2, sizeof(G));
            for (int i = 0; i < 4; i ++)
                for (int j = 0; j < 4; j ++)
                    if (G[i][j] == '.') G[i][j] = 'O';
            if (judge() != '-') found = 1;
            if (!found) printf("Case #%d: Draw\n", tc + 1);
            else printf("Case #%d: Game has not completed\n", tc + 1);
        }
    }

    return 0;
}
