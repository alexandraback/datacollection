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

int a[22];
int res[5000000];

int main (int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        for (int i = 0; i < 20; ++i)
            cin >> a[i];
        memset(res, -1, sizeof(res));
        bool ok = false;
        printf("Case #%d:\n", t + 1);
        for (int I = 1; I < (1 << 20); ++I) {
            int s = 0;
            for (int i = 0; i < 20; ++i) {
                if (I & (1 << i)) {
                    s += a[i];
                }
            }
            if (res[s] != -1) {
                ok = true;
                for (int i = 0; i < 20; ++i) 
                    if (res[s] & (1 << i))
                        printf("%d ", a[i]);
                printf("\n");
                for (int i = 0; i < 20; ++i) 
                    if (I & (1 << i))
                        printf("%d ", a[i]);
                printf("\n");
                break;
            }
            res[s] = I;
        }
        if (!ok)
            printf("Impossible\n");
    }
    
    
   
    return 0;
}

