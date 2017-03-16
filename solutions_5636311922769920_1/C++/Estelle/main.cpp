//
//  main.cpp
//  fractiles
//
//  Created by Estelle :) on 9/4/16.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ", i);
        long long int k,c,s;
        scanf("%lld%lld%lld", &k, &c, &s);
        if (k==1) printf("1\n");
        else if (c==1) {
            if (s<k) printf("IMPOSSIBLE\n");
            else {
                for (int j=1; j<=k; j++) printf("%d ", j);
                printf("\n");
            }
        }
        else if (s*c<k) printf("IMPOSSIBLE\n");
        else {
            long long int p=1;
            for (int m=0; m<s; m++) {
                bool stop=false;
                long long int cr=p;
                for (int j=1; j<c; j++) {
                    cr=(cr-1)*k+p+1;
                    p++;
                    if (p==k) {
                        stop=true; p--;
                    }
                }
                if (p<k-1) p++;
                printf("%lld ", cr);
                if (stop) break;
            }
            printf("\n");
        }
    }
}
