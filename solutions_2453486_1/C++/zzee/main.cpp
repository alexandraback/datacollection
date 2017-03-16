#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int check(char bo[10][10]) {
    bool flag[8];
    for (int i = 0; i < 8; ++i) {
        flag[i] = true;
    }

    for (int i = 0; i < 4; ++i) {
        if (bo[i][0]!='X'&&bo[i][0]!='T' ||bo[i][1]!='X'&&bo[i][1]!='T' ||
            bo[i][2]!='X'&&bo[i][2]!='T' ||bo[i][3]!='X'&&bo[i][3]!='T') {
            flag[0] = false;
        } else {
            flag[0] = true;
        }
        if (flag[0]) {
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[0][i]!='X'&&bo[0][i]!='T' ||bo[1][i]!='X'&&bo[1][i]!='T' ||
            bo[2][i]!='X'&&bo[2][i]!='T' ||bo[3][i]!='X'&&bo[3][i]!='T') {
            flag[1] = false;
        } else {
            flag[1] = true;
        }
        if (flag[1]) {
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[i][i]!='X'&&bo[i][i]!='T') {
            flag[2] = false;
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[i][3-i]!='X'&&bo[i][3-i]!='T') {
            flag[3] = false;
            break;
        }
    }

    //'O'
    for (int i = 0; i < 4; ++i) {
        if (bo[i][0]!='O'&&bo[i][0]!='T' ||bo[i][1]!='O'&&bo[i][1]!='T' ||
            bo[i][2]!='O'&&bo[i][2]!='T' ||bo[i][3]!='O'&&bo[i][3]!='T') {
            flag[4] = false;
        } else {
            flag[4] = true;
        }
        if (flag[4]) {
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[0][i]!='O'&&bo[0][i]!='T' ||bo[1][i]!='O'&&bo[1][i]!='T' ||
            bo[2][i]!='O'&&bo[2][i]!='T' ||bo[3][i]!='O'&&bo[3][i]!='T') {
            flag[5] = false;
        } else {
            flag[5] = true;
        }
        if (flag[5]) {
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[i][i]!='O'&&bo[i][i]!='T') {
            flag[6] = false;
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (bo[i][3-i]!='O'&&bo[i][3-i]!='T') {
            flag[7] = false;
            break;
        }
    }
    if (flag[0]||flag[1]||flag[2]||flag[3]) {
        return 1;
    } else if(flag[4]||flag[5]||flag[6]||flag[7]) {
        return 2;
    } else {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (bo[i][j]=='.') {
                    return 0;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int n;
    fin >> n;
    char board[10][10];
    for (int xx = 0; xx < n; ++xx) {
        for (int i = 0; i < 4; ++i) {
            fin >> board[i];
        }
        int aa = check(board);
        if (aa == 1) {
            fout << "Case #" << xx+1 << ": X won" << endl;

        } else if (aa == 2) {
             fout << "Case #" << xx+1 << ": O won" << endl;
        } else if (aa == 0) {
             fout << "Case #" << xx+1 << ": Game has not completed" << endl;

        } else if (aa == -1) {
            fout << "Case #" << xx+1 << ": Draw" << endl;

        }

    }
    return 0;
}
