#include <cstdio>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; ++i)

const int MAX_T = 1000 + 20;

int T;
char G[4][4];

bool go(int r, int c, int dr, int dc, char ch) {
    int eq = 0, t = 0; 
    REP(i, 4) {
        if (G[r][c] == ch) ++eq;
        else if (G[r][c] == 'T') ++t;
        r += dr, c += dc;
    }
    return eq == 4 || eq == 3 && t == 1;
}

bool win(char ch) {
    REP(r, 4) if (go(r, 0, 0, 1, ch)) return true;
    REP(c, 4) if (go(0, c, 1, 0, ch)) return true;
    if (go(0, 0, 1, 1, ch)) return true;
    if (go(3, 0, -1, 1, ch)) return true;
    return false;
}

bool done() {
    REP(r, 4) REP(c, 4)
        if (G[r][c] == '.') return false;
    return true;
}

int main() {
    scanf("%d", &T);
    REP(t, T) {
        REP(r, 4) scanf("%s", G + r);
        printf("Case #%d: ", t + 1);
        if (win('X')) puts("X won");
        else if (win('O')) puts("O won");
        else if (done()) puts("Draw");
        else puts("Game has not completed");
    }
}
