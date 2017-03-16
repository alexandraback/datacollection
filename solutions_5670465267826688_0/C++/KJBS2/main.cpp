//
//  main.cpp
//  C. Dijkstra
//
//  Created by KJBS2 on 2015. 4. 11..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_L 11111

int L, X;
char Data[MAX_L];

int S[2][2] =
{
    {0, 1},
    {1, 0}
};
int FS[4][4] =
{
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};
int FF[4][4] =
{
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

int Change[200];

struct LIST{
    int s;
    int f;
};

LIST Multi(LIST X, LIST Y) {
    int ns1  =  S[X.s][Y.s];
    int ns2  = FS[X.f][Y.f];
    int nows =  S[ns1][ns2];
    int nowf = FF[X.f][Y.f];
    return {nows, nowf};
}

void PROCESS(int TC) {
    scanf("%d%d", &L, &X);
    scanf("%s", Data+1);
    
    Change['i'] = 1;
    Change['j'] = 2;
    Change['k'] = 3;
    
    LIST all_i = {0, 0};
    LIST all_k = {0, 0};
    LIST all_x = {0, 0};
    
    for(int i=1; i<=L; i++) {
        int nowf = Change[Data[i]];
        all_i = Multi(all_i, {0, nowf});
    }
    for(int i=L; i>=1; i--) {
        int nowf = Change[Data[i]];
        all_k = Multi({0, nowf}, all_k);
    }
    
    
    
    for(int i=1; i<=X%4; i++) {
        all_x = Multi(all_x, all_i);
    }
    
    if(all_x.s != 1 || all_x.f != 0) {
        printf("Case #%d: NO\n", TC);
        return;
    }
    
    LIST now_i = {0, 0};
    LIST now_k = {0, 0};
    
    int p_i = -1, i_i = -1;
    int p_k = -1, i_k = -1;
    
    for(int p=0; p<4; p++) {
        LIST find = now_i;
        bool for_break = false;
        for(int i=1; i<=L; i++) {
            int nowf = Change[Data[i]];
            find = Multi(find, {0, nowf});
            
            if(find.s == 0 && find.f == 1) {
                for_break = true;
                p_i = p; i_i = i;
                break;
            }
        }
        if(for_break) break;
        now_i = Multi(now_i, all_i);
    }
    
    for(int p=0; p<4; p++) {
        LIST find = now_k;
        bool for_break = false;
        for(int i=L; i>=1; i--) {
            int nowf = Change[Data[i]];
            find = Multi({0, nowf}, find);
            
            if(find.s == 0 && find.f == 3) {
                for_break = true;
                p_k = p; i_k = L-i+1;
                break;
            }
        }
        if(for_break) break;
        now_k = Multi(all_k, now_k);
    }
    
    if(p_i == -1 || p_k == -1) {
        printf("Case #%d: NO\n", TC);
        return;
    }
    int sum_p = p_i + p_k;
    int sum_i = i_i + i_k;
    
    if(sum_i > L) {
        sum_i -= L;
        sum_p += 1;
    }
    
    if(sum_p < X) {
        printf("Case #%d: YES\n", TC);
        return;
    }else{
        printf("Case #%d: NO\n", TC);
        return;
    }
    
    return;
}

int main() {
    freopen("/Users/kjb/Desktop/input.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/ouptut.txt", "w", stdout);
    
    int T; scanf("%d", &T);
    
    for(int i=1; i<=T; i++)
        PROCESS(i);
    
    return 0;
}




