#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

char board[5][5];
bool check(int player) {
    char patten;
    if (player == 1) {
        patten = 'X';
    } else {
        patten = 'O';
    }
    for (int i = 0; i < 4; i++) {
        int count = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == patten || board[i][j] == 'T') {
                count++;
            }
            if (count == 4) {
                return true;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i][j] == patten || board[i][j] == 'T') {
                count++;
            }
            if (count == 4) {
                return true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (board[i][i] == patten || board[i][i] == 'T') {
            count++;
        }
    }
    if (count == 4) {
        return true;
    }
    count = 0;
    for (int i = 0; i < 4; i++) {
        if (board[i][3 - i] == patten || board[i][3 - i] == 'T') {
            count++;
        }
    }
    if (count == 4) {
        return true;
    }
    return false;
}

int main(void) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("dataout.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        for (int i = 0; i < 4; i++) {
            scanf("%s", board[i]);
        }
        if (check(1)) {
            printf("Case #%d: X won\n", cases);
        } else if (check(2)) {
            printf("Case #%d: O won\n", cases);
        } else {
            int mark = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (board[i][j] == '.') {
                        mark = 1;
                        break;
                    }
                }
                if (mark) {
                    break;
                }
            }
            if (mark) {
                printf("Case #%d: Game has not completed\n", cases);
            } else {
                printf("Case #%d: Draw\n", cases);
            }
        }
    }
    return 0;
}
