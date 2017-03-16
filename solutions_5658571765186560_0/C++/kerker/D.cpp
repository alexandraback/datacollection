#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main(){
    
    int T;
    scanf(" %d",&T);
    for(int t=0,X,N,M;t<T && scanf(" %d %d %d",&X,&N,&M)==3;t++){
        if(N>M) swap(N,M);
        if(((N*M)%X) != 0){
            printf("Case #%d: RICHARD\n",t+1);
            continue;
        }
        if(X==1 || X==2){
            printf("Case #%d: GABRIEL\n",t+1);
            continue;
        }
        if(X==3){
            if(N==1 && M==3)    printf("Case #%d: RICHARD\n",t+1);
            else    printf("Case #%d: GABRIEL\n",t+1);
            continue;
        }
        if(X==4){ 
            if((N==2 && M==2) || (N==1 && M==4) || (N==2 && M==4))    printf("Case #%d: RICHARD\n",t+1);
            else    printf("Case #%d: GABRIEL\n",t+1);
            continue;
        }
    }

    return 0;
}
