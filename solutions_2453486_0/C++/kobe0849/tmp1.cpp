#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char map[10][10];
bool check(char c){
    for(int i = 1; i <= 4; i++){
        int j;
        for( j = 1; j <= 4; j++){
           if(map[i][j] == c || map[i][j] == 'T'  )
           continue;
           else break;
        }
        if(j == 5) return true;
        for( j = 1; j <= 4; j++){
           if(map[j][i] == c || map[j][i] == 'T'  )
           continue;
           else break;
        }
        if(j == 5) return true;
    }
    int k;
    for( k = 1; k <= 4; k++){
        if(map[k][k] == c || map[k][k] == 'T'){
          continue;
        }else break;
    }
    if(k == 5) return true;

    for( k = 1; k <= 4; k++){
        if(map[k][5-k] == c || map[k][5-k] == 'T'){
          continue;
        }else break;
    }
    if(k == 5) return true;
    return false;
}
bool check(){
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++){
            if(map[i][j] == '.') return false;
        }
        return true;
}
int main(){
    int T;
    freopen("in.in","r",stdin);
    freopen("outt.txt","w",stdout);
    cin>>T;
    for(int cas = 1; cas <= T; cas++){
       for(int i = 1; i <= 4; i++){
           scanf("%s",map[i]+1);
       }
       printf("Case #%d: ",cas);
       if(check('X')){
           printf("X won\n");
       }else if(check('O')){
           printf("O won\n");
       }else if(check()){
           printf("Draw\n");
       }else{
           printf("Game has not completed\n");
       }
    }
    return 0;
}
