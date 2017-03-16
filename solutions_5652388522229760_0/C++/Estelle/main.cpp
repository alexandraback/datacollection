//
//  main.cpp
//  sheep
//
//  Created by Estelle :) on 9/4/16.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", i);
        if (n==0) printf("INSOMNIA\n");
        else {
            int a=0;
            int x=0;
            while (a!=(1<<10)-1) {
                x+=n;
                int p=x;
                while (p!=0) {
                    a|=(1<<(p%10));
                    p/=10;
                }
            }
            printf("%d\n", x);
        }
    }
}
