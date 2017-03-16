//
//  main.cpp
//  jamcoins
//
//  Created by Estelle :) on 9/4/16.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int t, n, j;
    scanf("%d%d%d", &t, &n, &j);
    printf("Case #1:\n");
    long long int dvs[9];
    for (int i=0; i<9; i++) {
        long long int x=i+2;
        x*=x, x*=x, x*=x, x*=x;
        dvs[i]=x+1;
    }
    long long int a=(1LL<<15)+1;
    for (int i=0; i<(1<<14); i++) {
        if (j==0) break;
        j--;
        long long int c=a+(i<<1);
        c=(c<<16)+c;
        for (int k=31; k>=0; k--) {
            if (1<<k & c) printf("1");
            else printf("0");
        }
        printf(" ");
        for (int k=0; k<9; k++) {
            printf("%lld%c", dvs[k], k==8 ? '\n' : ' ');
        }
    }
}
