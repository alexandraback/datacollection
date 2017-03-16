//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int T;  //num of Test
    freopen("/Users/daisy/Documents/GCJ/GCJ/B-large.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/B-large.out","w",stdout);
    string s;
    int R;
    // insert code here...
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        R = 0;
        cin >> s;
        if (s[s.size()-1]=='-') R++;
        for (int j = 0; j < s.size()-1; ++j){
            if (s.at(j) != s.at(j+1)) R++;
        }
        printf("Case #%d: %d\n", i, R);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
