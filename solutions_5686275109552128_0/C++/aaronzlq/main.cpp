//
//  main.cpp
//  Main
//
//  Created by AIdancer on 15/4/3.
//  Copyright (c) 2015年 AIdancer. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 1005;
int T, D, p[N];

int main(int argc, const char * argv[]) {
    cin >> T;
    for(int Case = 1; Case <= T; Case++) {
        cin >> D;
        for(int i = 0; i < D; i++)  cin >> p[i];
        sort(p, p+D);
        int ans = p[D-1];
        for(int i = 1; i <= p[D-1]; i++) {
            int sum = 0;
            for(int j = 0; j < D; j++) {
                if(p[j] <= i)  continue;
                sum += p[j]/i;
                if(p[j] % i == 0)  --sum;
            }
            ans = min(ans, sum+i);
        }
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}















