#include <cstdio>
#include <cstring>

const int maxn = 5;

char str[maxn][maxn];

bool full() {
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            if (str[i][j] == '.') return 0;
        }
    }
    return 1;
}

bool check(int val) {
    char ch = !val ? 'X' : 'O';
    for (int i = 0; i < 4; ++ i) {
        int flag = 1;
        for(int j = 0; j < 4; ++ j) {
            if (str[i][j] != ch && str[i][j] != 'T') flag = 0;
        }
        if (flag) return 1;
    }
    for (int i = 0; i < 4; ++ i) {
        int flag = 1;
        for(int j = 0; j < 4; ++ j) {
            if (str[j][i] != ch && str[j][i] != 'T') flag = 0;
        }
        if (flag) return 1;
    }
    int flag = 1;
    for (int i = 0; i < 4; ++ i) {
        if (str[i][i] != ch && str[i][i] != 'T') flag = 0;
    }
    if (flag) return 1;
    flag = 1;
    for (int i = 0; i < 4; ++ i) {
        if (str[i][3 - i] != ch && str[i][3 - i] != 'T') flag = 0;
    }
    return flag;
}

int main() {
    int cas;
    scanf("%d", &cas);
    for (int t = 1; t <= cas; ++ t) {
        printf("Case #%d: ", t);
        for (int i = 0; i < 4; ++ i) scanf("%s", str[i]);
        if (check(0)) puts("X won");
        else if (check(1)) puts("O won");
        else if (full()) puts("Draw");
        else puts("Game has not completed");
    }
    return 0;
}
