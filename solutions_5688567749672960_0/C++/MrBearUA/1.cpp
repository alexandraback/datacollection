//
//  main.cpp
//  FHC_Pattern
//
//  Created by Andriy Medvid on 11.01.15.
//  Copyright (c) 2015 Andriy Medvid. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAX_NUM 1000010

#define IN_NAME ("/Users/andriymedvid/Desktop/A-small-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/A-small-attempt0.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int res[MAX_NUM];

int rev(int k) {
    int a = 0;
    while(k > 0) {
        a = (a * 10) + (k % 10);
        k /= 10 ;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int n;
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        memset(res, 0, sizeof(int) * MAX_NUM);
        res[1] = 1;
        
        cin >> n;
        
        queue<pair<int, int>> qu;
        
        qu.push(make_pair(1, 2));
        
        while(res[n] == 0)
        {
            if(res[qu.front().second] == 0) {
                res[qu.front().second] = res[qu.front().first] + 1;
                qu.push(make_pair(qu.front().second, qu.front().second+1));
                qu.push(make_pair(qu.front().second, rev(qu.front().second)));
            }
            qu.pop();
        }
        
        OutCase(tIter);
        // out answer
        cout << res[n];
        
        cout << endl;
    }
    
    return 0;
}


