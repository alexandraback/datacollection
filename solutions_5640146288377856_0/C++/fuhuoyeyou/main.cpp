//
//  main.cpp
//  p2
//
//  Created by 默默 on 15-4-2.
//  Copyright (c) 2015年 默默. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MA 200005
int r, c,w;

int main(int argc, const char * argv[]) {
    //freopen("/Users/momo/Desktop/xcode_data/in.txt", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/A-small-attempt0.in", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/out.txt", "w", stdout);
    
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    int cas;
   
    cin >> cas;
    int cc = 0;
    while (cc++ < cas){
        cin >> r >> c >> w;
        int times = c / w;
        times = times * r;
        if (c % w != 0){
            times += w;
        }
        else{
            times += w - 1;
        }
        printf("Case #%d: %d\n", cc, times);
        
    }
    return 0;
}







