//
//  main.cpp
//  gcj-1c-c
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

int main(int argc, const char * argv[])
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T;
    cin >> T;
    int n, m, k;
    for(int t = 0; t < T; t++) {
        cin >> n >> m >> k;
        if(n < 3 || m < 3 || k < 5) {
            printf("Case #%d: %d\n", t+1, k);
            continue;
        }
        k += 4;
        int Min = min(n, m);
        int Sqrt = (int)sqrt(k+0.1);
        int Short = (Sqrt * (Sqrt + 1) >= k) ? Sqrt : Sqrt+1;
        Short = min(Short, Min);
        int rest = 0;
        if((k%Short) == 1) {
            k--;
            rest = 1;
        }
        int Long = (k + Short - 1) / Short;
        int result = 2 * (Short + Long - 4);
        printf("Case #%d: %d\n", t+1, result+rest);
    }
    return 0;
}

