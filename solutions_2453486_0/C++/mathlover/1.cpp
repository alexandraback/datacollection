#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<cmath>

using namespace std;
string board[5];
bool check_win(char c)
{
    for(int i=0;i<4;++i){
        int cntc = 0;
        int cntT = 0;
        for(int j=0;j<4;++j){
            if(board[i][j]==c)
                cntc++;
            else if(board[i][j]=='T')
                cntT++;
        }
        if(cntc==4 || (cntc==3 && cntT == 1))
            return true;
    }
    for(int i=0;i<4;++i){
        int cntc = 0;
        int cntT = 0;
        for(int j=0;j<4;++j){
            if(board[j][i]==c)
                cntc++;
            else if(board[j][i]=='T')
                cntT++;
        }
        if(cntc==4 || (cntc==3 && cntT == 1))
            return true;
    }

    int cntc = 0; int cntT = 0;
    for(int i=0;i<4;++i){
        if(board[i][i]==c) cntc++;
        else if(board[i][i]=='T') cntT++;
        if(cntc==4 || (cntc==3 && cntT == 1))
            return true;
    }

    cntc=0; cntT=0;
    for(int i=0;i<4;++i){
        if(board[i][3-i]==c) cntc++;
        else if(board[i][3-i]=='T') cntT++;
        if(cntc==4 || (cntc==3 && cntT == 1))
            return true;
    }
    return false;
}
void gao(int idx)
{
    if( check_win('X'))
        cout << "Case #" << idx << ": X won" << endl;
    else if(check_win('O'))
        cout << "Case #" << idx << ": O won" << endl;
    else{
        int cntdot = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
               if(board[i][j]=='.') 
                   cntdot++;
            }
        }
        if(cntdot)
            cout << "Case #" << idx << ": Game has not completed" << endl;
        else 
            cout << "Case #" << idx << ": Draw" << endl;
    }
}
int main()
{
    int T; cin >> T;
    int idx = 0;
    while(T--){
        idx++;
       for(int i=0;i<4;i++){
            cin >> board[i]; 
       }
       gao(idx);
    }
}
