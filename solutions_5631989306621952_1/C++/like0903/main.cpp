//
//  main.cpp
//  codejam
//
//  Created by 李科 on 16/4/9.
//  Copyright © 2016年 李科. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int LL;


string getstring(int k, int n) {
    ostringstream s1;
    int d[30];
    for (int i = n; i >= 0; i--) {
        d[i] = k % 2;
        k = k / 2;
    }
    d[0] = d[n + 1] = 1;
    for (int i = 0; i <= n + 1; i++) {
        s1 << d[i];
    }
    return s1.str();
}


int main(int argc, const char * argv[]) {
    
    ifstream cin("/Users/like/Downloads/A-large.in");
   ofstream cout("/Users/like/Desktop/Github/googlecodejam/codejam/codejam/A-large-attempt2.out");
    

    
    int t;
    cin >> t;
    
    
    for (int tt = 1; tt <= t; tt++) {
        string s;
        
        cin >> s;
        
        string ans = s.substr(0, 1);
        
        for (int i = 1; i < s.size(); i++) {
            if (ans[0] > s[i]) {
                ans += s[i];
            }
            else {
                ans = s[i] + ans;
            }
        }
        
        
        cout << "Case #" << tt << ": " << ans << endl;
        
    }
    
    return 0;
}
