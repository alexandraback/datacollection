#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

char board[4][4];
int T;

void read_board()
{
    char line[6];
    for (int i = 0;i < 4;i++) {
        fgets(line, sizeof(line), stdin);
        for (int j = 0;j < 4;j++) {
            board[i][j] = line[j];
        }
    }
    fgets(line, sizeof(line), stdin);
}

char check_board()
{
    //  Check row.
    for (int i = 0;i < 4;i++) {
        if (
            (board[i][0] == 'X' || board[i][0] == 'T') && 
            (board[i][1] == 'X' || board[i][1] == 'T') && 
            (board[i][2] == 'X' || board[i][2] == 'T') && 
            (board[i][3] == 'X' || board[i][3] == 'T')) {
            return 'X';
        }
        if (
            (board[i][0] == 'O' || board[i][0] == 'T') && 
            (board[i][1] == 'O' || board[i][1] == 'T') && 
            (board[i][2] == 'O' || board[i][2] == 'T') && 
            (board[i][3] == 'O' || board[i][3] == 'T')) {
            return 'O';
        }
    }
    //  Check column.
    for (int j = 0;j < 4;j++) {
        if (
            (board[0][j] == 'X' || board[0][j] == 'T') && 
            (board[1][j] == 'X' || board[1][j] == 'T') && 
            (board[2][j] == 'X' || board[2][j] == 'T') && 
            (board[3][j] == 'X' || board[3][j] == 'T')) {
            return 'X';
        }
        if (
            (board[0][j] == 'O' || board[0][j] == 'T') && 
            (board[1][j] == 'O' || board[1][j] == 'T') && 
            (board[2][j] == 'O' || board[2][j] == 'T') && 
            (board[3][j] == 'O' || board[3][j] == 'T')) {
            return 'O';
        }
                
    }
    //  Check diag.
    if (
        (board[0][0] == 'X' || board[0][0] == 'T') && 
        (board[1][1] == 'X' || board[1][1] == 'T') && 
        (board[2][2] == 'X' || board[2][2] == 'T') && 
        (board[3][3] == 'X' || board[3][3] == 'T')) {
        return 'X';
    }
    if (
        (board[0][0] == 'O' || board[0][0] == 'T') && 
        (board[1][1] == 'O' || board[1][1] == 'T') && 
        (board[2][2] == 'O' || board[2][2] == 'T') && 
        (board[3][3] == 'O' || board[3][3] == 'T')) {
        return 'O';
    }
    if (
        (board[0][3] == 'X' || board[0][3] == 'T') && 
        (board[1][2] == 'X' || board[1][2] == 'T') && 
        (board[2][1] == 'X' || board[2][1] == 'T') && 
        (board[3][0] == 'X' || board[3][0] == 'T')) {
        return 'X';
    }
    if (
        (board[0][3] == 'O' || board[0][3] == 'T') && 
        (board[1][2] == 'O' || board[1][2] == 'T') && 
        (board[2][1] == 'O' || board[2][1] == 'T') && 
        (board[3][0] == 'O' || board[3][0] == 'T')) {
        return 'O';
    }
    //  Check completeness.
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            if (board[i][j] == '.') {
                return 'N';
            }
        }
    }

    return 'D';
}

int main(int argc, char **argv)
{
    scanf("%d\n", &T);
    for (int t = 0;t < T;t++) {
        read_board();
        char r = check_board();

        printf("Case #%d: ", t + 1);
        if (r == 'X') {
            printf("X won\n");
        } else if (r == 'O') {
            printf("O won\n");
        } else if (r == 'D') {
            printf("Draw\n");
        } else if (r == 'N') {
            printf("Game has not completed\n");
        }
    }

    return 0;
}

