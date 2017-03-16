//
//  main.cpp
//  A. Standing Ovation
//
//  Created by KJBS2 on 2015. 4. 11..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_N 2222

int N;
char Number[MAX_N];

void PROCESS(int p) {
    scanf("%d", &N);
    scanf("%s", Number);
    
    int sum = 0;
    int ans = 0;
    for(int i=0; i<=N; i++) {
        int now = Number[i] - '0';
        
        if(now == 0) continue;
        if(sum < i) {
            ans += i - sum;
            sum  = i;
        }
        sum += now;
    }
    
    printf("Case #%d: %d\n", p, ans);
}

int main() {
    freopen("/Users/kjb/Desktop/input.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/ouptut.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for(int i=1; i<=T; i++)
        PROCESS(i);
    
    return 0;
}





