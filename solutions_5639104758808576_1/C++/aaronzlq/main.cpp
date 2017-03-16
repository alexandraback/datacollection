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

int T, Smax;
char str[1005];

int main(int argc, const char * argv[]) {
//    freopen("./input", "r", stdin);
    cin >> T;
    for(int Case = 1; Case <= T; Case++) {
        cin >> Smax >> str;
        ++Smax;
        int ans = 0, sum = 0;
        for(int i = 0; i < Smax; i++) {
            int amount = str[i] - '0';
            if(i <= sum)  sum += amount;
            else {
                ans += i-sum;
                sum = i + amount;
            }
        }
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}















