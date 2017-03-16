#include<cstdio>
#include<cstring>
char map[5][5];

int gao(int ch) {
    int ok, i, j;
    for (i = 0; i < 4; ++i) {
        ok = 1;
        for (j = 0; j < 4; ++j)
            if (map[i][j] != 'T' && map[i][j] != ch) {
                ok = 0;
                break;
            }
        if (ok)
            return 1;
    }
    for (i = 0; i < 4; ++i) {
        ok = 1;
        for (j = 0; j < 4; ++j)
            if (map[j][i] != 'T' && map[j][i] != ch) {
                ok = 0;
                break;
            }
        if (ok)
            return 1;
    }
    ok = 1;
    for (i = 0; i < 4; ++i)
        if (map[i][i] != 'T' && map[i][i] != ch) {
            ok = 0;
            break;
        }
    if (ok)
        return 1;   
    ok=1;
    for (i = 0; i < 4; ++i)
        if (map[i][3 - i] != 'T' && map[i][3 - i] != ch) {
            ok = 0;
            break;
        }
    if (ok)
        return 1;
    return 0;
}

int over() {
    int i, j;
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (map[i][j] == '.')
                return 0;
    return 1;
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T, i, j, t = 0;
    scanf("%d", &T);
    while (T--) {
        for (i = 0; i < 4; ++i){
            scanf("%s", map[i]);
          //  printf("i=%d %s\n",i,map[i]);
        }
        scanf("%*c");
        printf("Case #%d: ", ++t);
        if (gao('X'))
            printf("X won\n");
        else if (gao('O'))
            printf("O won\n");
        else if (over())
            printf("Draw\n");
        else
            printf("Game has not completed\n");
    }
    return 0;
}