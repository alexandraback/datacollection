#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>

using namespace std;

int r,c,w;

int main(){

    int t; scanf("%d",&t);
    for(int it=1;it<=t;it++){
        printf("Case #%d: " , it);
        scanf("%d%d%d",&r,&c,&w);
        printf("%d\n" , (c+w-1)/w*r+w-1 );
    }

    return 0;
}