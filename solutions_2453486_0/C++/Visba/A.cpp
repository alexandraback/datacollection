
#include <cstdlib>
#include <cstdio>

char board[4][5];
int X, O, T, N, win;
char winner;

void count(char ch) {
    switch (ch) {
        case 'X':
            X++;
            break;
        case 'O':
            O++;
            break;
        case 'T':
            T++;
            break;
        default:
            N++;
            break;
    }
}

int checkWin() {
    if (X + T == 4) {
        win = 1;
        winner = 'X';
        return 1;
    }
    else if (O + T == 4) {
        win = 1;
        winner = 'O';
        return 1;
    }
    return 0;
}

void checkBoard() {
    N = win = 0;
    do {
        for (int row = 0; row < 4; row++) {
            X = O = T = 0;
            for (int col = 0; col < 4; col++) {
                count(board[row][col]);
            }
            if (checkWin()) {
                break;
            }
        }
        for (int col = 0; col < 4; col++) {
            X = O = T = 0;
            for (int row = 0; row < 4; row++) {
                count(board[row][col]);
            }
            if (checkWin()) {
                break;
            }
        }
        X = O = T = 0;
        for (int row = 0; row < 4; row++) {
            count(board[row][row]);
        }
        if (checkWin()) {
            break;
        }
        X = O = T = 0;
        for (int row = 0; row < 4; row++) {
            count(board[row][3 - row]);
        }
        if (checkWin()) {
            break;
        }
    } while(0);
}


int main(int argc, const char * argv[])
{
    int cn;
    
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    
    scanf("%d\n", &cn);
    
    for (int ci = 1; ci <= cn; ci++) {
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
        }

        checkBoard();
        
        if (win) {
            printf("Case #%d: %c won", ci, winner);
        }
        else {
            if (N > 0) {
                printf("Case #%d: Game has not completed", ci);
            }
            else {
                printf("Case #%d: Draw", ci);
            }
        }
        printf("\n");
    }
    
    return 0;
}

