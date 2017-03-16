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
    
    ifstream cin("/Users/like/Downloads/A-small-attempt1.in");
    ofstream cout("/Users/like/Desktop/Github/googlecodejam/codejam/codejam/C-small-attempt0.out");
    

    
    int t;
    cin >> t;
    
    
    for (int tt = 1; tt <= t; tt++) {
        string s;
        
        cin >> s;
        
        vector<string> v;
        
        v.push_back(s.substr(0, 1));
        
        for (int i = 1; i < s.size(); i++) {
            vector<string> p;
            
            for (int j = 0; j < v.size(); j++) {
                p.push_back(v[j] + s[i]);
                p.push_back(s[i] + v[j]);
            }
            v = p;
        }
        
        sort(v.begin(), v.end());
        
        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            if (v[i].size() == s.size()) {
                if (ans == "") ans = v[i];
                else ans = max(ans, v[i]);
            }
        }
        
        
        cout << "Case #" << tt << ": " << ans << endl;
        
    }
    
    return 0;
}
