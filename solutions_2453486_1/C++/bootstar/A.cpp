#include <iostream>
#include <stdio.h>
using namespace std;
char str[10][10];

int check(){
    //hor
    for(int i = 1; i <= 4; i ++){
        bool flag = true;
        // check x
        for(int j = 1; j <= 4; j ++){
            if(str[i][j] == 'X' || str[i][j]=='T') continue;
            else {flag = false; break;}
        }
        if(flag){ return 1;}
        flag = true;
        //check O
        for(int j = 1; j <= 4; j ++){
            if(str[i][j] == 'O' || str[i][j]=='T') continue;
            else {flag = false; break;}
        }
        if(flag){ return 2;}
    }
    //vec
    for(int i = 1; i <= 4; i ++){
        bool flag = true;
        for(int j = 1; j <= 4; j ++){
            if(str[j][i] == 'X' || str[j][i]=='T') continue;
            else {flag = false; break;}
        }
        if(flag){ return 1;}

        flag = true;
        for(int j = 1; j <= 4; j ++){
            if(str[j][i] == 'O' || str[j][i] == 'T') continue;
            else{flag = false; break;}
        }
        if(flag) return 2;
    }

    bool flag = true;
    for(int i = 1; i <= 4; i ++){
        if(str[i][i] == 'X' || str[i][i]=='T') continue;
        else {flag = false; break;}
    }
    if(flag) return 1;
    flag = true;
    for(int i = 1; i <= 4; i ++){
        if(str[i][i] == 'O' || str[i][i]=='T') continue;
        else {flag = false; break;}
    }
    if(flag) return 2;

    flag = true;
    for(int i = 1; i <= 4; i ++){
        if(str[i][5-i] == 'X' || str[i][5-i]=='T') continue;
        else {flag = false; break;}
    }
    if(flag) return 1;
    flag = true;

    for(int i = 1; i <= 4; i ++){
        if(str[i][5-i] == 'O' || str[i][5-i]=='T') continue;
        else {flag = false; break;}
    }
    if(flag) return 2;

    for(int i = 1; i <= 4; i ++){
        for(int j = 1; j <= 4; j ++){
            if(str[i][j]=='.'){
                return 3;
            }
        }
    }
    return 4;
}

int main()
{
    int T, cas = 1;
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &T);
    getchar();
    while(cas <= T){
        for(int i= 1; i <= 4; i ++){
            for(int j = 1; j <= 4; j ++)
                str[i][j] = getchar();
            getchar();
        }
        getchar();

        printf("Case #%d: ", cas ++);
        int ans = check();
        if(ans == 1){
            printf("X won\n");
        }
        else if(ans==2){
            printf("O won\n");
        }
        else if(ans == 3){
            printf("Game has not completed\n");
        }
        else{
            printf("Draw\n");
        }
    }
    return 0;
}
