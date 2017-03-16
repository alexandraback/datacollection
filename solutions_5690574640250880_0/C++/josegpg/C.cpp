#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T, R, C, M, gCount;
char board[60][60];

void UltimateFILL() {
    int count = 0;
    for (int i = 0; i < R-2 && count < M; i++) {
        for (int j = 0; j < C-2 && count < M; j++) {
            board[i][j] = '*';
            count++;
            if (j+1 == C-2 && count + 2 <= M) {
                board[i][j+1] = '*';
                board[i][j+2] = '*';
                count += 2;
            }
            
            if (i+1 == R-2 && count + 2 <= M) {
                board[i+1][j] = '*';
                board[i+2][j] = '*';
                count += 2;
            }
        }
    }
    
    gCount += count;
}

void fillRelax(int r, int c) {
    int count = 0;
    for (int i = 0; i < r && count < M; i++)
        for (int j = 0; j < c && count < M; j++) {
            board[i][j] = '*';
            count++;
        }
    
    gCount += count;
}

void fill2Relax(int r) {
    int count = 0;
    for (int i = 0; i < r && count+2 <= M; i++) {
        board[i][0] = '*';
        board[i][1] = '*';
        count+=2;
    }
    
    gCount += count;
}

void printBoard() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cout << board[i][j] << (j == C-1 ? "\n": "");
}

void printBoardT() {
    for (int i = 0; i < C; i++)
        for (int j = 0; j < R; j++)
            cout << board[j][i] << (j == R-1 ? "\n": "");
}

void solve(bool t) {
    
    if (C == 1) {
        fillRelax(R, C);
        (t? printBoardT():printBoard());
        return;
    }
    
    if (C == 2) fill2Relax(R-2);
    
    UltimateFILL();
    
    if (R*C - gCount - 1 == 3 && M - gCount == 3) {
        board[R-1][C-2] = '*';
        board[R-2][C-1] = '*';
        board[R-2][C-2] = '*';
        gCount += 3;
    }
    
    if (M - gCount != 0) printf("Impossible\n");
    else (t? printBoardT():printBoard());
        
}

int main() {
    cin >> T;
    bool Tras;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C >> M;
        if (R < C) {
            Tras = true;
            swap(R, C);
        } else
            Tras = false;
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                board[i][j] = '.';
        
        board[R-1][C-1] = 'c';
        gCount = 0;
        printf("Case #%d:\n", t);
        solve(Tras);
    }
    
    return 0;
}
