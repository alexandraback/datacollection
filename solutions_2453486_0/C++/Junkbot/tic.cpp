#include <cstdio>

const int MAX_N = 5;

int T;
int N = 4;

char board[MAX_N][MAX_N];

bool check(char target) {
    // go down
    for(int j=0;j<N;j++) {
        bool win = true;
        for(int i=0;i<N;i++) {
            if(board[i][j] != target && board[i][j] != 'T') {
                win = false;
                break;
            }
        }

        if(win) {
            return true;
        }
    }

    // go right
    for(int i=0;i<N;i++) {
        bool win = true;
        for(int j=0;j<N;j++) {
            if(board[i][j] != target && board[i][j] != 'T') {
                win = false;
                break;
            }
        }

        if(win) {
            return true;
        }
    }

    // diagonals

    bool win = true;
    for(int i=0;i<N;i++) {
        if(board[i][i] != target && board[i][i] != 'T') {
            win = false;
            break;
        }
    }

    if(win) {
        return true;
    }

    win = true;
    
    for(int i=0;i<N;i++) {
        if(board[i][N-i-1] != target && board[i][N-i-1] != 'T') {
            win = false;
            break;
        }
    }

    if(win) {
        return true;
    }

    return false;
}

bool isFull(void) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(board[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ", z);

        for(int i=0;i<N;i++) {
            scanf(" %s ",board[i]);
        }

        if(check('X')) {
            printf("X won\n");
        } else if(check('O')) {
            printf("O won\n");
        } else if(isFull()) {
            printf("Draw\n");
        } else {
            printf("Game has not completed\n");
        }
    }

    return 0;
}
