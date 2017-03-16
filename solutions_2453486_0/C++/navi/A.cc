#include <cstdio>
#include <cstring>

const char* ans[] = {
    "X won",
    "O won",
    "Draw",
    "Game has not completed"
};

int T;
char s[4][5];

int gao(int cx, int cy, int dx, int dy) {
    int ret = 3;
    for (int i = 0; i < 4; ++i) {
        int nx = (cx + dx * i) % 4;
        int ny = (cy + dy * i) % 4;
        if (s[nx][ny] == '.') {
            return 0;
        } else if (s[nx][ny] == 'X') {
            ret &= 1;
        } else if (s[nx][ny] == 'O') {
            ret &= 2;
        }
    }
    return ret;
}

int gao() {
    int cur;
    for (int i = 0; i < 4; ++i) {
        cur = gao(i, 0, 0, 1);
        if (cur != 0) {
            return __builtin_ctz(cur);
        }
        cur = gao(0, i, 1, 0);
        if (cur != 0) {
            return __builtin_ctz(cur);
        }
    }
    cur = gao(0, 0, 1, 1);
    if (cur != 0) {
        return __builtin_ctz(cur);
    }
    cur = gao(3, 0, -1, 1);
    if (cur != 0) {
        return __builtin_ctz(cur);
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i][j] == '.') {
                return 3;
            }
        }
    }
    return 2;
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        for (int i = 0; i < 4; ++i) {
            scanf("%s", s[i]);
        }
        printf("Case #%d: %s\n", caseNum, ans[gao()]);
    }
    return 0;
}
