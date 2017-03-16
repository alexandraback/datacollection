//
// Created by mark on 4/8/16.
//
#include "includes.h"
#include <vector>
#include <iterator>
#include <algorithm>

int solve(int num) {
    string s = "";
    cin >> s ;
    vector<int> cakes(s.size()) ;
    for(std::string::size_type i = 0; i < s.size(); ++i) {
        if(s[i] == '-')
            cakes [i] = 0;
        else
            cakes[i] = 1;
    }
    // add last 1
    cakes.push_back(1);
    debug << print_vector(cakes) << endl;
    int ans = 0 ;
    int status = 1;
    for (auto rit = cakes.rbegin(); rit != cakes.rend(); ++rit) {
        if(status == 1 && *rit == 0) {
            status = -1;
            ans += 1;
        } else if ( status == -1 && *rit == 1) {
            status = 1;
            ans += 1;
        }
    }

    debug << num << endl;

    return ans;
}