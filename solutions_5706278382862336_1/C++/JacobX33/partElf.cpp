//
//  main.cpp
//  partElf
//
//  Created by Jacob on 11/05/14.
//  Copyright (c) 2014 Jacob. All rights reserved.
//

#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int nrOfCases;
    
    long long int powersOf2[41];
    powersOf2[0] = 1;
    
    for (int i=1; i<41; i++) {
        powersOf2[i] = 2*powersOf2[i-1];
    }
    
    scanf("%d", &nrOfCases);
    
    for (int i=0; i<nrOfCases; i++) {
        long long p, q;
        scanf("%lld/%lld", &p, &q);
        
        while (p%2 == 0 && q%2 == 0) {
            p = p/2;
            q = q/2;
        }
        
        bool ok = false;
        
        for (int j=0; j<41; j++) {
            if (q%powersOf2[j] == 0 && q%powersOf2[j+1] != 0) {
                long long a = q/powersOf2[j];
                if (p%a == 0) {
                    p = p/a;
                    q = q/a;
                    ok = true;
                    break;
                }
                else break;
            }
        }
        
        if (!ok) {
            printf("Case #%d: impossible\n", i+1);
            continue;
        }
        
        int k = 0;
        bool isPowerOf2 = false;
        
        for (int j=0; j<41; j++) {
            if (powersOf2[j] == q) {
                k = j;
                isPowerOf2 = true;
            }
        }
        
        long double x = double(p)/double(q);
        long double y;
        
        if (!isPowerOf2) {
            printf("Case #%d: impossible\n", i+1);
            continue;
        }
        
        if (p == 1) {
            printf("Case #%d: %d\n", i+1, k);
        }
        
        else {
            for (int j=1; j<41; j++) {
                y = double(1)/double(powersOf2[j]);
                if (x >= y) {
                    printf("Case #%d: %d\n", i+1, j);
                    break;
                }
            }
        }
    }
    
    return 0;
}

