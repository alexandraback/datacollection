#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
char board[6][6];
int chk(char tar){
    int cnt = 0;
    for(int i=0;i<4;i++){
        cnt = 0;
        for(int j=0;j<4;j++){
            if(board[i][j] == tar || board[i][j] == 'T'){
                cnt++;
            }
        }
        if(cnt == 4){
            return 1;
        }
    }
    for(int j=0;j<4;j++){
        cnt = 0;
        for(int i=0;i<4;i++){
            if(board[i][j] == tar || board[i][j] == 'T'){
                cnt++;
            }
        }
        if(cnt == 4){
            return 1;
        }
    }
    
    cnt = 0;
    for(int i=0;i<4;i++){
        if(board[i][i] == tar || board[i][i] == 'T'){
            cnt++;
        }
    }
    if(cnt==4){
        return 1;
    }

    cnt = 0;
    for(int i=0;i<4;i++){
        if(board[i][4-i-1] == tar || board[i][4-i-1] == 'T'){
            cnt++;
        }
    }
    if(cnt==4){
        return 1;
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        int nf = 0;
        for(int i=0;i<4;i++){
            scanf("%s", board[i]);
            for(int j=0;j<4;j++){
                if(board[i][j] == '.'){
                    nf = 1;
                }
            }
        }
        int X = chk('X');
        int O = chk('O');
        printf("Case #%d: ",f);
        if(X==1 && O==0){
            printf("X won\n");
        }else if(X==0 && O==1){
            printf("O won\n");
        }else if(nf == 0){
            printf("Draw\n");
        }else{
            printf("Game has not completed\n");
        }
    }
    return 0;
}
