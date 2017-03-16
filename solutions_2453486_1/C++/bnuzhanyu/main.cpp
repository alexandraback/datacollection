#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


bool check(string board[], int tx, int ty , char rep)
{
    if(tx!=-1) board[tx][ty] = rep;
    string winner(4, rep);
    for(int i=0; i<4; ++i){
        if(board[i] == winner) return true;
    }

    for(int j=0; j<4; ++j){
        string tmp;
        for(int i=0; i<4; ++i)
        tmp.push_back(board[i][j]);
        if(tmp == winner) return true;
    }

    string diag1, diag2;
    for(int i=0; i<4; ++i){
        diag1.push_back(board[i][i]);
        diag2.push_back(board[i][3-i]);
    }
    if(diag1 == winner) return true;
    if(diag2 == winner) return true;

    return false;
}

int main()
{
    int T;
    fstream fin("A-large.in");
    fstream fout("A-large.out", ios_base::out);
    fin>>T;

    for(int ca=1; ca<=T; ++ca){

        int xWin=0, oWin=0;
        bool isBlank = 0;
        string board[4];
        int tx=-1, ty=-1;

        for(int i=0; i<4; ++i)
        {
            fin>>board[i];
            for(int j=0; j<4; ++j)
            if(board[i][j] == 'T') tx=i, ty=j;
            else if(board[i][j] =='.')isBlank = true;
        }

        //check:
        xWin = check(board, tx, ty, 'X');
        oWin = check(board, tx, ty, 'O');

        fout<<"Case #"<<ca<<": ";
        if(xWin) fout << "X won" << endl;
        else if(oWin) fout << "O won" << endl;
        else if(isBlank) fout << "Game has not completed" << endl;
        else fout<< "Draw" <<endl;

    }
    return 0;
}
