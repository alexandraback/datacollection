//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
    int T;  //num of Test
    string S, R;
    freopen("/Users/daisy/Documents/A-small-attempt1.in","r",stdin);
    freopen("/Users/daisy/Documents/A-small-attempt1.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> S;
        R = S.at(0);
        for (int j = 1; j < S.size(); ++j) {
            if(S.at(j) >= R.at(0))
                R = S.at(j) + R;
            else
                R = R + S.at(j);
        }
        printf("Case #%d: %s\n", i, R.c_str());
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
