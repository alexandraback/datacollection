//
//  Solution.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include "Solution.h"
#include <string>

void doCase(ifstream& file,int index, string &s)
{
    string ans;
    
    int maxS;
    file >> maxS;
    string s1;
    file >> s1;
    
    int friendNum = 0;
    int num = 0;
    for (int i = 0; i <= maxS; ++i) {
        int p = s1[i] - '0';
        if (num < i) {
            friendNum += i - num;
            num += i - num;
        }
        num += p;
    }
    ans = to_string(friendNum);
    
    s += "Case #" + to_string(index) + ": " + ans + "\n";
}
/*
 if(getline(file,line) && line.length() > 0)
 {
 
 
 s += "Case #" + to_string(index) + ": " + ans + "\n";
 }*/