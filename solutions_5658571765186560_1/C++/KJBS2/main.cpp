//
//  main.cpp
//  D. Ominous Omino
//
//  Created by KJBS2 on 2015. 4. 11..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

int X, N, M;
void PROCESS(int TC) {
    scanf("%d%d%d", &X, &N, &M);
    
    if(X>=7) {
        printf("Case #%d: RICHARD\n", TC);
        return;
    }
    int all = N*M;
    if(all%X != 0) {
        printf("Case #%d: RICHARD\n", TC);
        return;
    }
    if(X==1 || X==2) {
        printf("Case #%d: GABRIEL\n", TC);
        return;
    }
    if(X==3) {
        if(N==1 || M==1)
            printf("Case #%d: RICHARD\n", TC);
        else
            printf("Case #%d: GABRIEL\n", TC);
        return;
    }
    if(X==4) {
        if(N<=2 || M<=2)
            printf("Case #%d: RICHARD\n", TC);
        else
            printf("Case #%d: GABRIEL\n", TC);
        return;
    }
    if(X==5) {
        if(N<=3 || M<=3)
            printf("Case #%d: RICHARD\n", TC);
        else
            printf("Case #%d: GABRIEL\n", TC);
    }
    if(X==6) {
        if(N<=3 || M<=3)
            printf("Case #%d: RICHARD\n", TC);
        else
            printf("Case #%d: GABRIEL\n", TC);
    }
}

int main() {
    freopen("/Users/kjb/Desktop/input.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/output.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    
    for(int i=1; i<=T; i++)
        PROCESS(i);
    
    return 0;
}




