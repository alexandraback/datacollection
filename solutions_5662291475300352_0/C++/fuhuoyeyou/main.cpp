//
//  main.cpp
//  p3
//
//  Created by 默默 on 15-4-2.
//  Copyright (c) 2015年 默默. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    //freopen("/Users/momo/Desktop/xcode_data/in.txt", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/C-small-1-attempt0.in", "r", stdin);
    freopen("/Users/momo/Desktop/xcode_data/out.txt", "w", stdout);
    
    //ifstream fin = ifstream("/Users/momo/Desktop/userProfile/user_profile1.txt");
    int cas;
    cin >> cas;
    int cc = 0;
    int n;
    while (cc++ < cas){
        cin >> n;
        vector<pair<int, int> > vect;
        for (int i = 0; i < n; ++i){
            int x1,x2,x3;
            cin >> x1 >> x2 >> x3;
            if (x2 == 1)
               // make_pair(1,2);
                vect.push_back(make_pair(x1, x3));
            else{
                vect.push_back(make_pair(x1, x3));
                vect.push_back(make_pair(x1, x3 + 1));
            }
        }
        double x1 = (360.0-vect[0].first)/360.0*vect[0].second;
        double x2 = (360.0-vect[1].first)/360.0*vect[1].second;
        double x3 = (720.0-vect[0].first)/360.0*vect[0].second;
        double x4 = (720.0-vect[1].first)/360.0*vect[1].second;
        int ans = 1;
        if (x1 < x2 && x3 > x2){
            ans = 0;
        }
        if (x2 < x1 && x4 > x1){
            ans = 0;
        }
        //cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;

        printf("Case #%d: %d\n", cc, ans);
    }
    return 0;
}

