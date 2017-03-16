//
//  main.cpp
//  gcj-1c-a
//
//  Created by Andriy Medvid' on 11.05.14.
//  Copyright (c) 2014 Andriy Medvid'. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

long long GCD(long long a, long long b) {
    if(b == 0)
        return a;
    return GCD(b, a%b);
}


int main(int argc, const char * argv[])
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    
    long long p, q;
    for(int t = 0; t < T; t++) {
        scanf("%lld/%lld", &p, &q);
        long long gcd = GCD(p, q);
        p /= gcd;
        q /= gcd;
        int ppower = 0, qpower = 0;
        while(q != 0) {
            qpower++;
            if(p != 0)
                ppower++;
            if((q & 1)) break;
            p /= 2;
            q /= 2;
        }
        if(q == 1) {
            printf("Case #%d: %d\n", t+1, qpower - ppower);
        } else {
            printf("Case #%d: impossible\n", t+1);
        }
    }
    return 0;
}


