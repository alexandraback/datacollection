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

#define IN_NAME ("/Users/andriymedvid/Downloads/A-large.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/A-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    int r,c,w;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        cin >> r >> c >> w;
        
        OutCase(tIter);
        // out answer
        
        cout << (c - 1) / w + w + (r - 1)*(c / w);
        
        cout << endl;
    }
    
    return 0;
}


