#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char board[10][10];


bool iscomplete(){
    for (int i=0;i<4;++i){
        for (int j=0;j<4;++j){
            if ( board[i][j]=='.' ){
                return false;
            }
        }
    }
    return true;
}

bool down(int r,int c,char x){

    if ( r+3 >= 4 )return false;
    int cnt=0,t=0;
    for (int i=0;i<4;++i){
        if ( board[r+i][c]==x ){
            cnt++;
        }else if ( board[r+i][c]=='T' ){
            t++;
        }
    }
    return  cnt==4 || (cnt==3 && t==1);
}


bool right(int r,int c,char x){

    if ( c+3 >= 4 )return false;
    int cnt=0,t=0;
    for (int i=0;i<4;++i){
        if ( board[r][c+i]==x ){
            cnt++;
        }else if ( board[r][c+i]=='T' ){
            t++;
        }
    }
    return  cnt==4 || (cnt==3 && t==1);
}

bool diag(int r,int c,char x){

    if ( c+3 >= 4 || r+3>=4 )return false;
    int cnt=0,t=0;
    for (int i=0;i<4;++i){
        if ( board[r+i][c+i]==x ){
            cnt++;
        }else if ( board[r+i][c+i]=='T' ){
            t++;
        }
    }
    return  cnt==4 || (cnt==3 && t==1);
}

bool diag2(int r,int c,char x){

    if ( c-3 <0 || r+3>=4 )return false;
    int cnt=0,t=0;
    for (int i=0;i<4;++i){
        if ( board[r+i][c-i]==x ){
            cnt++;
        }else if ( board[r+i][c-i]=='T' ){
            t++;
        }
    }
    return  cnt==4 || (cnt==3 && t==1);
}


bool iswin(char c){

    for (int i=0;i<4;++i){
        for (int j=0;j<4;++j){
            if ( down(i,j,c) || right(i,j,c) || diag(i,j,c) || diag2(i,j,c) ){
                return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        printf("Case #%d: ",kk);
        for (int i=0;i<4;++i){
            scanf("%s",board[i]);
        }

        if ( iswin('X') ){
            printf("X won\n");
        }else if ( iswin('O') ){
            printf("O won\n");
        }else if ( iscomplete() ){
            printf("Draw\n");
        }else{
            printf("Game has not completed\n");
        }
    }
    return 0;
}
