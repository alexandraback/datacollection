//
//  main.cpp
//  Google
//
//  Created by Mec0825 on 13-4-13.
//  Copyright (c) 2013年 Mec0825. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

int T;

bool isVowal(char p) {
    if(p == 'a' || p == 'e' ||
       p == 'i' || p == 'o' ||
       p == 'u') return true;
    return false;
}

char str[1000010];
bool last[1000010];
int n;

void Solve() {
    scanf("%s %d", str, &n);
    
    int cnt = 0;
    int len = (int)strlen(str);
    
    for(int i = 0; i < len; i++) {
        if(!isVowal(str[i])) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        
        if(cnt >= n) {
            last[i] = 1;
        }
        else {
            last[i] = 0;
        }
    }
    
    int p = -1;
    long long res = 0;
    
    for(int i = 0; i < len; i++) {
        if(last[i]) {
            p = i;
            res += (long long)(i-n+2);
        }
        else {
            if(p != -1 && p+1 >= n) res += (long long)(p-n+2);
        }
    }
    
    printf("%lld", res);
}

int main()
{
    freopen("/Users/Mec0825/Documents/Google/2013/Round 1C/A-in.txt", "r", stdin);
    freopen("/Users/Mec0825/Documents/Google/2013/Round 1C/A-out.txt", "w", stdout);
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ",i+1);
        Solve();
        printf("\n");
    }
    
    return 0;
}
