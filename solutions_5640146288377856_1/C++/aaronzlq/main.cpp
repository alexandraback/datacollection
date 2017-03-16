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
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;



int main(int argc, const char * argv[]) {
    int T, R, C, W;
    cin >> T;
    for(int Case = 1; Case <= T; Case++) {
        cin >> R >> C >> W;
        int ans = R * (C/W);
        if(C%W != 0)  ++ans;
        ans += W-1;
        printf("Case #%d: %d\n", Case, ans);
    }
    return 0;
}















