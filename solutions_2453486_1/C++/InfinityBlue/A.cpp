#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
#define INF 0x73737373
#define EPS 1e-8
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
char board[4][5];
bool check_empty()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(board[i][j] == '.') return true;
    return false;
}

bool check_x()
{
    for(int i = 0; i < 4; i++){
        bool row = true, col = true;
        for(int j = 0; j < 4; j++){
            if(board[i][j] != 'X' && board[i][j] != 'T') row = false;
            if(board[j][i] != 'X' && board[j][i] != 'T') col = false;
        }
        if(row || col) return true;
    }
    bool ld = true, rd = true;
    for(int i = 0; i < 4; i++){
        if(board[i][i] != 'X' && board[i][i] != 'T') ld = false;
        if(board[i][4-i-1] != 'X' && board[i][4-i-1] != 'T') rd = false;
    }
    if(ld || rd) return true;
    return false;
}

bool check_o()
{
    for(int i = 0; i < 4; i++){
        bool row = true, col = true;
        for(int j = 0; j < 4; j++){
            if(board[i][j] != 'O' && board[i][j] != 'T') row = false;
            if(board[j][i] != 'O' && board[j][i] != 'T') col = false;
        }
        if(row || col) return true;
    }
    bool ld = true, rd = true;
    for(int i = 0; i < 4; i++){
        if(board[i][i] != 'O' && board[i][i] != 'T') ld = false;
        if(board[i][4-i-1] != 'O' && board[i][4-i-1] != 'T') rd = false;
    }
    if(ld || rd) return true;
    return false;
}
int main()
{
    int t;
    freopen("A-large.in.", "r", stdin);
    freopen("ans.out", "w", stdout);
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++){
        for(int i = 0; i < 4; i++)
            scanf("%s", board[i]);
        printf("Case #%d: ",ca);
        if(check_x()){
            puts("X won");
        } else if(check_o()){
            puts("O won");
        } else if(check_empty()){
            puts("Game has not completed");
        } else {
            puts("Draw");
        }
    }
}
