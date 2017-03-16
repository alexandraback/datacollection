// GCJ2014_R1_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int T;
int R,C,M;
char board[64][64];
int flag[64][64];
int Count;
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void flood(int y, int x)
{
    if (y<0 || x<0 || y>=R || x>=C) {
        return;
    }
    if (flag[y][x] != 1) {
        return;
    }
    flag[y][x] = 2;
    Count++;
    bool mine = false;
    for (int i=0; i<8; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny<0 || nx<0 || ny>=R || nx>=C) {
            continue;
        }
        if (flag[ny][nx] == 0) {
            mine = true;
            break;
        }
    }
    if (!mine) {
        for (int i=0; i<8; i++) {
            flood(y+dy[i], x+dx[i]);
        }
    }
}

bool check()
{
    Count = 0;
    flood(0,0);
    return (Count == M);
}

void solve_it()
{
    scanf("%d%d%d", &R, &C, &M);
    M = R*C - M;

    for (int r=1; r<=R; r++) {
        int c = (M - 1) / r + 1;
        if (c > C) {
            continue;
        }
        int left = (M-1) % c + 1;
        
        for (int y=0; y<R; y++) {
            for (int x=0; x<C; x++) {
                flag[y][x] = 0;
                board[y][x] = '*';
            }
        }
        for (int y=0; y<r-1; y++) {
            for (int x=0; x<c; x++) {
                flag[y][x] = 1;
                board[y][x] = '.';
            }
        }
        for (int x=0; x<left; x++) {
            flag[r-1][x] = 1;
            board[r-1][x] = '.';
        }
        if (left == 1 && r > 2 && c != 1) {
            board[r-1][1] = '.';
            flag[r-1][1] = 1;
            board[r-2][c-1] = '*';
            flag[r-2][c-1] = 0;
        }
        if (check()) {                        
            board[0][0] = 'c';
            for (int y=0; y<R; y++) {
                for (int x=0; x<C; x++) {
                    printf("%c",board[y][x]);
                }
                printf("\n");
            }
            return;
        }        
    }
    //printf("%d %d %d\n", R, C, M);
    printf("Impossible\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\C-small-attempt2.in", "rb", stdin);
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\C-small-attempt2.out", "wb", stdout);
    scanf("%d",&T);
    for (int ca=1; ca<=T; ca++)
    {        
        printf("Case #%d:\n", ca);
        solve_it();                
    }
	return 0;
}

