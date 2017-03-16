//
//  main.cpp
//  C. Hiking Deer
//
//  Created by KJBS2 on 2015. 5. 3..
//  Copyright (c) 2015년 KJBS2. All rights reserved.
//

#include <stdio.h>

#define MAX_N 10

int N;
struct HIKER{
    int x;
    int m;
}H[MAX_N];

int main() {
    freopen("/Users/kjb/Desktop/Cinput.txt", "r", stdin);
    freopen("/Users/kjb/Desktop/Couptut.txt", "w", stdout);
    
    
    int T; scanf("%d", &T);
    for(int p=1; p<=T; p++) {
        N = 0;
        
        int N1; scanf("%d", &N1);
        for(int i=1; i<=N1; i++) {
            int X, N2, M;
            scanf("%d%d%d", &X, &N2, &M);
            for(int j=N+1; j<=N+N2; j++) {
                H[j].x = X;
                H[j].m = M;
            }
            N += N2;
        }
        
        if(N==2) {
            if( H[1].m == H[2].m ) {
                printf("Case #%d: %d\n", p, 0);
                continue;
            }
            long long t1 = 1ll * (H[2].x - H[1].x) * (H[1].m * H[2].m);
            long long t2 = 1ll * 360. * (H[2].m - H[1].m);
            
            if(t1 <= 0 && t2 <= 0) {
                t1 *= -1;
                t2 *= -1;
            }
            
//            printf("%lld / %lld\n", t1, t2);
            
            if(1ll*H[1].x*t2*H[1].m + 1ll*360*t1 >= 360*t2*H[1].m) {
                printf("Case #%d: %d\n", p, 0);
                continue;
            }else{
                printf("Case #%d: %d\n", p, 1);
                continue;
            }
        }

    }
    
    
    return 0;
}






