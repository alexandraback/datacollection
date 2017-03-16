#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int sum(char* arr, int start, int inc) {
    int s = 0;
    for (int i = 0; i < 4; ++i) {
        s += arr[start + i * inc];
    }
    return s;
}

int main(int argc, char** argv) {
    int round;
    char board[16];
    scanf("%d", &round);
    for (int r = 1; r <= round; ++r) {
        bool notComplete = false, win = false;
        for (int i = 0; i < 4; ++i) {
            scanf("%s", board + 4 * i);
        }
        int dir[10];
        for (int i = 0; i < 4; ++i) {
            dir[i] = sum(board, 4 * i, 1);
        }
        for (int i = 0; i < 4; ++i) {
            dir[4 + i] = sum(board, i, 4);
        }
        dir[8] = sum(board, 0, 5);
        dir[9] = sum(board, 3, 3);
        for (int i = 0; i < 10; ++i) {
            if (dir[i] == 4 * 'X' || dir[i] == 3 * 'X' + 'T') {
                printf("Case #%d: X won\n", r);
                win = true;
                break;
            } else if (dir[i] == 4 * 'O' || dir[i] == 3 * 'O' + 'T') {
                printf("Case #%d: O won\n", r);
                win = true;
                break;
            } else if (dir[i] < 4 * 'O') {
                notComplete = true;
            }
        }
        if (!win) {
            if (notComplete) {
                printf("Case #%d: Game has not completed\n", r);
            } else {
                printf("Case #%d: Draw\n", r);
            }
        }
    }
    return 0;
}

