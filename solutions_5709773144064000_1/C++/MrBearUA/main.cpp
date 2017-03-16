//
//  main.cpp
//  GCJ-2014-b
//
//  Created by Andriy Medvid' on 12.04.14.
//  Copyright (c) 2014 Andriy Medvid'. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    cin >> T;
    
    double C, F, X;
    int N;
    for(int t = 0; t < T; t++) {
        double time = 0;
        cin >> C >> F >> X;
        N = max((int)(X/C - 2.0 / F + 0.000000001), 0);
        for(int i = 0; i < N; i++) {
            time += C / (2.0 + F*i);
        }
        time += X / (2.0 + F*N);
        printf("Case #%d: %.7lf\n", t+1, time);
    }
    return 0;
}

