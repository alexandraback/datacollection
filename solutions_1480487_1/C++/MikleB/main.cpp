//
//  main.cpp
//  Contest
//
//  Created by User on 25.03.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int n;
int s[111];
int S;

bool test(double pj, int j) {
    double P = 1 - pj;
    double val = s[j] + pj * S;
    for (int i = 0; i < n; ++i) {
        if (i != j) {
            // s + p * S = val
            double p = (val - s[i]) / S;
            if (p < 0)
                p = 0;
            P -= p;
        }
    }
    return P < -1e-8;
}

int main (int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        scanf("%d", &n);
        S = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            S += s[i];
        }
        printf("Case #%d:", t + 1);
        for (int j = 0; j < n; ++j) {
            double l = 0;
            double r = 1;
            while (l + 1e-8 < r) {
                double m = (l + r) / 2;
                if (test(m, j))
                    r = m;
                else
                    l = m;
            }
            printf(" %.5lf", l * 100);
        }
        printf("\n");
    }
    
    
   
    return 0;
}

