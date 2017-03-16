#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
    int T, x, y;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",t);
        int step  = 1;
        while( x!=0 ){
            if( x<0 ){
                printf("EW"); x+=1; step+=2;
            }else{
                printf("WE"); x-=1; step+=2;
            }
        }
        while( y!=0 ){
            if( y<0 ){
                printf("NS"); y+=1; step+=2;
            }else{
                printf("SN"); y-=1; step+=2;
            }
        }
        printf("\n");
    }
    return 0;
}

