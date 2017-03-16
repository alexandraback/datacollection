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

bool myfunc(const vector<long>& vec1, const vector<long>& vec2){
    for(size_t i = 0; i < vec1.size() && i < vec2.size(); i++){
        if(vec1[i] > vec2[i]){
            return false;
        } else if(vec1[i] < vec2[i]){
            return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    ifstream cin("/Users/like/Downloads/B-small-attempt0.in");
    ofstream cout("/Users/like/Desktop/Github/googlecodejam/codejam/codejam/B-small-attempt2.out");
    

    int t;
    cin >> t;
    
    for (int tt = 1; tt <= t; tt++) {
        
        int n;
        int v[2505];
        memset(v, 0, sizeof(v));
        
        cin >> n;
        
        for (int i = 0; i < n * 2 - 1; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                v[x] ++;
            }
        }
        
        vector<int> d;
        
        for (int i = 0; i <= 2500; i++) {
//            if (v[i]) {
//                cout << i << " " << v[i] << endl;
//            }
            if (v[i] % 2) {
                d.push_back(i);
            }
        }
        
        cout << "Case #" << tt << ":";
        for (int i = 0; i < d.size(); i++) {
            cout << " " << d[i];
        }
        cout << endl;
        
    }
    
    return 0;
}


