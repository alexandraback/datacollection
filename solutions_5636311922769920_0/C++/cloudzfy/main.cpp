//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MIN(a,b) (a)<(b)?(a):(b)
#define eps 1e-15
long long K_pow[101];
int main(int argc, const char * argv[]) {
    int T;
    long long K, C, S;
    freopen("D-small-attempt0.in.txt","r",stdin);
    freopen("D-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld", &K, &C, &S);
        K_pow[0] = 1;
        for (int i = 1; i <= C; i++) {
            K_pow[i] = K_pow[i - 1] * K;
        }
        printf("Case #%d:",t);
        if (K - C + 1 > S) {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < S; i++) {
            long long myans = 0;
            int count = C - 1;
            for (int j = i; j < C + i; j++) {
                myans += K_pow[count] * (j % K);
                count--;
            }
            printf(" %lld",myans + 1);
        }
        printf("\n");
    }
    return 0;
}
