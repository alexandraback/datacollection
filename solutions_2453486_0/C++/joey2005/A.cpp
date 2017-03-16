#include <cstdio>
using namespace std;

char board[10][10];

bool check(char character) {
    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; j < 4; ++j) {
            if (board[i][j] != character && board[i][j] != 'T') {
                break;
            }
        }
        if (j == 4) {
            return true;
        }
    }
    for (int j = 0; j < 4; ++j) {
        int i;
        for (i = 0; i < 4; ++i) {
            if (board[i][j] != character && board[i][j] != 'T') {
                break;
            }
        }
        if (i == 4) {
            return true;
        }
    }
    int k;
    for (k = 0; k < 4; ++k) {
        if (board[k][k] != character && board[k][k] != 'T') {
            break;
        }
    }
    if (k == 4) {
        return true;
    }
    for (k = 0; k < 4; ++k) {
        if (board[k][3 - k] != character && board[k][3 - k] != 'T') {
            break;
        }
    }
    if (k == 4) {
        return true;
    }
    return false;
}

void solve() {
    for (int i = 0; i < 4; ++i) {
        scanf("%s", board[i]);
        //fprintf(stderr, "%s\n", board[i]);
    }
    bool left = false;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == '.') {
                left = true;
            }
        }
    }
    if (check('X')) {
        puts("X won");
    } else if (check('O')) {
        puts("O won");
    } else if (left) {
        puts("Game has not completed");
    } else {
        puts("Draw");
    }
}

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; testID++) {
        printf("Case #%d: ", testID);
        solve();
        fflush(stdout);
    } 

    fclose(stdin);
    fclose(stdout);
}
