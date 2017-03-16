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
        dvs[i]=pow(i+2, 8)+1;
    }
    long long int a=(1LL<<7)+1;
    for (int i=0; i<(1<<6); i++) {
        if (j==0) break;
        j--;
        long long int c=a+(i<<1);
        c=(c<<8)+c;
        for (int k=15; k>=0; k--) {
            if (1<<k & c) printf("1");
            else printf("0");
        }
        bool die=false;
        for (int base=2; base<=10; base++) {
            long long int num=0;
            for (int k=0; k<16; k++) {
                if (1<<k & c) num+=pow(base,k);
            }
            if (num%dvs[base-2]!=0) {
                die=true;
                break;
            }
        }
        if (die) break;
        printf(" ");
        for (int k=0; k<9; k++) {
            printf("%lld%c", dvs[k], k==8 ? '\n' : ' ');
        }
    }
}
