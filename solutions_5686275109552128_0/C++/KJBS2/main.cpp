//
//  main.cpp
//  B. Infinite House of Pancakes
//
//  Created by KJBS2 on 2015. 4. 11..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_D 2222
#define MAX_P 1000

int D;
int Nr[MAX_D];

void PROCESS(int k) {
    scanf("%d", &D);
    for(int i=0; i<D; i++)
        scanf("%d", &Nr[i]);
    
    int ans = MAX_P*MAX_P;
    
    for(int p=1; p<=MAX_P; p++) {
        int cnt = 0;
        for(int i=0; i<D; i++)
            cnt += (Nr[i]-1)/p;
        
        if(ans > cnt + p)
            ans = cnt + p;
    }
    
    printf("Case #%d: %d\n", k, ans);
}

int main() {
    freopen("/Users/kjb/Desktop/input.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/ouptut.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    
    for(int i=1; i<=T; i++)
        PROCESS(i);
    
    return 0;
}