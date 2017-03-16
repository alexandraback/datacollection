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

#define MAX_NUM 1000000000

#define IN_NAME ("/Users/andriymedvid/Documents/GCM-out/C-small-1-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/C-small-1-attempt0.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        int n;
        
        int d[12], h[12], m[12];
        
        cin >> n;
        
        for(int i = 0; i < n; i++)
            cin >> d[i] >> h[i] >> m[i];
        
        OutCase(tIter);
        // out answer
        
        if(n == 1 && h[0] == 1)
            cout << 0;
        else {
            if(n == 1) {
                if((720 - d[0]) * m[0] <= (360 - d[0]) * (m[0] + 1))
                    cout << 1;
                else
                    cout << 0;
            }
            else {
                int mn = (360 - d[0]) * m[0] < (360 - d[1]) * m[1] ? m[0] : m[1];
                int mx = (360 - d[0]) * m[0] < (360 - d[1]) * m[1] ? m[1] : m[0];
                int dn = (360 - d[0]) * m[0] < (360 - d[1]) * m[1] ? d[0] : d[1];
                int dx = (360 - d[0]) * m[0] < (360 - d[1]) * m[1] ? d[1] : d[0];
                
                if((720 - dn) * mn <= (360 - dx) * mx)
                    cout << 1;
                else
                    cout << 0;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}


