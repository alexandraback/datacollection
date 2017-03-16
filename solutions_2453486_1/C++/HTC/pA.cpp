#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
char MAP[4][4];
int ok(char ch,char in){
    if(in == '.')return 0;
    if(ch == in)return 1;
    if(in == 'T')return 1;
    return 0;
}
int check(){
    int i,j,cnt;
    char tmp;

    for(i=0;i<4;i++){
        tmp = 0;
        cnt = 0;
        for(j=0;j<4;j++){
            if(MAP[i][j] != 'T' && tmp == 0)tmp = MAP[i][j];
            cnt += ok(tmp,MAP[i][j]);
        }
        //printf("tmp %c\n",tmp);
        if(cnt == 4){
            if(tmp == 'O')return 0;
            else return 1;
        }
    }
    //printf("oAO\n");
    for(j=0;j<4;j++){

        tmp = 0;
        cnt = 0;
        for(i=0;i<4;i++){
            if(MAP[i][j] != 'T' && tmp == 0)tmp = MAP[i][j];
            cnt += ok(tmp,MAP[i][j]);
        }
        if(cnt == 4){
            if(tmp == 'O')return 0;
            else return 1;
        }
    }
    tmp = 0;
    cnt = 0;
    for(i=0;i<4;i++){
        if(MAP[i][i] != 'T' && tmp == 0)tmp = MAP[i][i];
        cnt += ok(tmp,MAP[i][i]);
    }
    if(cnt == 4){
        if(tmp == 'O')return 0;
        else return 1;
    }
    tmp = 0;
    cnt = 0;
    for(i=0;i<4;i++){
        if(MAP[i][3-i] != 'T' && tmp == 0)tmp = MAP[i][3-i];
        cnt += ok(tmp,MAP[i][3-i]);
    }
    if(cnt == 4){
        if(tmp == 'O')return 0;
        else return 1;
    }


    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            if(MAP[i][j] == '.')
                return 3;
    }
    return 2;
}
int main (){
    int flag,T,i,ca=0;
    scanf("%d",&T);
    while(T--){
        for(i=0;i<4;i++){
            scanf("%s",MAP[i]);
        }
        flag = check();
        ca++;
        printf("Case #%d: ",ca);
        if(flag == 0){
            printf("O won\n");
        }else if(flag == 1){
            printf("X won\n");
        }else if(flag == 2){
            printf("Draw\n");
        }else if(flag == 3){
            printf("Game has not completed\n");
        }
    }
    return 0;
}
