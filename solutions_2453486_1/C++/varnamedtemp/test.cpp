#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long

#define MAX_N 100
#define MAX_P_LEN 100000

char board[10][10];
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int c = 1;c<=T;c++) {
        for(int i = 0;i<4;i++)
            scanf("%s", board[i]);
        bool complete = true;
        for(int i = 0;i<4;i++)
            for(int j = 0;j<4;j++)
                if(board[i][j] == '.')
                    complete = false;

        bool xWin = false, oWin = false;
        for(int i = 0;i<4;i++) {
            int cntX = 0, cntO = 0, cntT = 0;
            for(int j = 0;j<4;j++) {
                if(board[i][j] == 'X') cntX++;
                if(board[i][j] == 'O') cntO++;
                if(board[i][j] == 'T') cntT++;
            }
            if(cntX + cntT == 4) xWin = true;
            if(cntO + cntT == 4) oWin = true;
        }

        for(int j = 0;j<4;j++) {
            int cntX = 0, cntO = 0, cntT = 0;
            for(int i = 0;i<4;i++) {
                if(board[i][j] == 'X') cntX++;
                if(board[i][j] == 'O') cntO++;
                if(board[i][j] == 'T') cntT++;
            }
            if(cntX + cntT == 4) xWin = true;
            if(cntO + cntT == 4) oWin = true;
        }

        int cntX = 0, cntO = 0, cntT = 0;
        for(int i = 0;i<4;i++) {
            if(board[i][i] == 'X') cntX++;
            if(board[i][i] == 'O') cntO++;
            if(board[i][i] == 'T') cntT++;
        }
        if(cntX + cntT == 4) xWin = true;
        if(cntO + cntT == 4) oWin = true;

        cntX = 0, cntO = 0, cntT = 0;
        for(int i = 0;i<4;i++) {
            if(board[i][4 - i - 1] == 'X') cntX++;
            if(board[i][4 - i - 1] == 'O') cntO++;
            if(board[i][4 - i - 1] == 'T') cntT++;
        }
        if(cntX + cntT == 4) xWin = true;
        if(cntO + cntT == 4) oWin = true;

        printf("Case #%d: ", c);

        if(xWin) printf("X won\n");
        else if(oWin) printf("O won\n");
        else if(complete) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
