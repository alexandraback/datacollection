#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int T,X,R,C;;

int main() {
    freopen("input.in","r",stdin);
    freopen("outputD","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) { 
        printf("Case #%d: ",t);
        scanf("%d%d%d",&X,&R,&C);
        if((R*C) % X) {
            printf("RICHARD\n");
            continue;
        }
        if(X<=2) {
            printf("GABRIEL\n");
            continue;
        }
        if(X==3) {
            if(R*C == 3) {
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        if(R<=2 || C<=2) {
            printf("RICHARD\n");
            continue;
        } else {
            printf("GABRIEL\n");
        }
    }
    return 0;
}
