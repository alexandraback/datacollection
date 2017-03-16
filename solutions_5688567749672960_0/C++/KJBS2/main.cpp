//
//  main.cpp
//  A. Counter Culture
//
//  Created by KJBS2 on 2015. 5. 3..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_N 10000000

int N;
int Nr[MAX_N+1];
int CC[MAX_N+1];
int Q[MAX_N+1], r, f;

int reverse(int n) {
    int result = 0;
    while(n != 0) {
        result *= 10;
        result += n%10;
        n/=10;
    }
    return result;
}

void HOW(int n) {
    printf("%d\n", n);
    if(n==1) return;
    if(CC[n] == 1) {
        HOW(n-1);
    }else{
        HOW(reverse(n));
    }
    return;
}

int main() {
    freopen("/Users/kjb/Desktop/input.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/ouptut.txt", "w", stdout);
    
    /*
    for(int i=1; i<=300; i++) {
        if(reverse(i) - i >= 0)
        printf("%d : %d\n", i, reverse(i) - i);
    }
    */
    
    r = f = -1;
    Q[++r] = 1;
    Nr[1] = 1;
    
    while(f<r) {
        int z = Q[++f];
        int k = Nr[z];
        
        int next = z+1;
        if(next <= MAX_N)
        if(Nr[next] == 0) {
            Q[++r] = next;
            Nr[next] = k+1;
            CC[next] = 1;
        }
        
        next = reverse(z);
        if(next <= MAX_N)
        if(Nr[next] == 0) {
            Q[++r] = next;
            Nr[next] = k+1;
            CC[next] = 2;
        }
    }
    
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++) {
        scanf("%d", &N);
        printf("Case #%d: %d\n", i, Nr[N]);
    }
    
    
    return 0;
}
