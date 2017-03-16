#include <cstdio>

using namespace std;

const int N = 4;
const char* OUTPUT[] = {"X won", "O won", "Draw", "Game has not completed"};
const char WILD_C = 'T';

char map[N+2][N+2];

void input() {
    for (int i=0; i<N; ++i) {
        scanf("%s", map[i]);
    }
}

bool is_same(int sx, int sy, int dx, int dy, int c) {
    for (int i=0; i<N; ++i) {
        if (map[sx][sy] != c && map[sx][sy] != WILD_C) {
            return false;
        }
        sx += dx;
        sy += dy;
    }
    return true;
}

int solve() {
    for (int i=0; i<N; ++i) {
        if (is_same(0, i, 1, 0, 'X')) return 0;
        if (is_same(0, i, 1, 0, 'O')) return 1;
        if (is_same(i, 0, 0, 1, 'X')) return 0;
        if (is_same(i, 0, 0, 1, 'O')) return 1;
    }
    if (is_same(0, 0, 1, 1, 'X')) return 0;
    if (is_same(0, 0, 1, 1, 'O')) return 1;
    if (is_same(N-1, 0, -1, 1, 'X')) return 0;
    if (is_same(N-1, 0, -1, 1, 'O')) return 1;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (map[i][j] == '.')
                return 3;
        }
    }

    return 2;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; ++i) {
        printf("Case #%d: ", i);
        input();
        int result = solve();
        printf("%s\n", OUTPUT[result]);
    }
}
