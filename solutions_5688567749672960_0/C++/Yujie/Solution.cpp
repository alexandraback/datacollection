//
//  Solution.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include "Solution.h"
#include <string>
#include <unordered_map>

static unordered_map<long long, int> map1;
vector<long long> max_vec;
int num;


long long reverse_long(long long t)
{
    long long m = 0;
    while (t ) {
        m *= 10;
        m += t % 10;
        t /= 10;
    }
    return m;
}

void doCase(ifstream& file,int index, string &s)
{
    string ans;
    
    long long count = 0;
    file >> count;
    if (map1.count(count) > 0) {
        ans = to_string(map1[count]);
        s += "Case #" + to_string(index) + ": " + ans + "\n";
        return;
    }
    else if(map1.count(1) == 0)
    {
        map1[1] = 1;
        max_vec.push_back(1);
        num = 1;
    }
    
    while (map1.count(count) == 0) {
        num++;
        vector<long long> v;
                for (int i = 0; i < max_vec.size(); ++i) {
            long long t = max_vec[i] + 1;
            if (map1.count(t) == 0) {
                v.push_back(t);
                map1[t] = num;
                
            }
            t = reverse_long(t - 1);
            if (map1.count(t) == 0) {
                v.push_back(t);
                map1[t] = num;
            }
        }
        max_vec = v;
    }
    ans = to_string(map1[count]);

    s += "Case #" + to_string(index) + ": " + ans + "\n";
}

