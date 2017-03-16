//
//  Solution.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include "Solution.h"
#include <string>

pair<char, bool> cal(pair<char, int> p1, pair<char, int> p2)
{
    bool flag = !(p1.second ^ p2.second);
    if (p1.first == '1') {
        return make_pair(p2.first, flag);
    }
    else if(p2.first == '1')
        return make_pair(p1.first, flag);
    else if(p1.first == 'i')
    {
        if (p2.first == 'i') {
            return make_pair('1', !flag);
        }
        else if(p2.first == 'j')
            return make_pair('k', flag);
        else
            return make_pair('j', !flag);
    }
    else if(p1.first == 'j')
    {
        
        if (p2.first == 'i') {
            return make_pair('k', !flag);
        }
        else if(p2.first == 'j')
            return make_pair('1', !flag);
        else
            return make_pair('i', flag);
    }
    else{
        if (p2.first == 'i') {
            return make_pair('j', flag);
        }
        else if(p2.first == 'j')
            return make_pair('i', !flag);
        else
            return make_pair('1', !flag);
    }
}

void doCase(ifstream& file,int index, string &s)
{
    string ans;
    
    long long L,X;
    file >> L >> X;
    string s1;
    file >> s1;
    int ind = 0;
    pair<char, int> p = make_pair('1', true);
    long long j = 0;
    for (j = 0; j < X; ++j) {
        for (long long i = 0; i < s1.length(); ++i) {
            p = cal(p, make_pair(s1[i], true));
            if (ind == 0) {
                if (p.first == 'i') {
                    ind++;
                    p = make_pair('1', p.second);
                }
            }
            else if(ind == 1){
                if (p.first == 'j') {
                    ind++;
                    p = make_pair('1', p.second);
                }
            }
            else if(ind == 2){
                if(p.first == 'k') {
                    ind++;
                    p = make_pair('1', p.second);
                }
            }
        }
        if (ind == 3) {
            ++j;
            break;
        }
        else if((ind == 0 && j > 2) || (ind == 1 && j > 6) || (ind == 0 && j > 10) )
            break;
        
    }
    if (j < X && ind == 3) {
        pair<char, int> q = make_pair('1', true);
        for (long long i = 0; i < s1.length(); ++i) {
            q = cal(q, make_pair(s1[i], true));
        }
        for (int k = 0; k < (X - j) % 4; ++k) {
            p = cal(p, q);
        }
    }
    
    
    if (ind == 3 && p.first == '1' && p.second) {
        ans = "YES";
    }
    else
        ans = "NO";
    
    s += "Case #" + to_string(index) + ": " + ans + "\n";
}
