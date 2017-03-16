//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int T;  //num of Test
    long long K, C, S, min, temp;
    long long index;
    freopen("/Users/daisy/Documents/D-large.in","r",stdin);
    freopen("/Users/daisy/Documents/D-large.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        //fuck = 0;
        cin >> K >> C >> S;
        printf("Case #%d:", i);
        min = ceil(K * 1.0/C);
        if (S < min) printf(" IMPOSSIBLE\n");
        else {
            if (C > K) {
                //fuck = C-K;
                C = K;
            }
            for (long j = 0; j < min-1; j++) {
                index = 1;
                temp = 1;
                for (long k = 0; k < C; k++) {
                    index += (j*C+C-1-k)*temp;
                    temp *= K;
                }
                printf(" %lld", index);
            }
            index = 1;
            temp = 1;
            for (long k = 0; k < C; k++) {
                index += (K-1-k)*temp;
                temp *= K;
            }
            //index *= pow(K,fuck);
            printf(" %lld\n", index);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
