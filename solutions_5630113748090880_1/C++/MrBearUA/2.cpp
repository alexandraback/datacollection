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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/B-large.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/B-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int heights[2510];
int n;

void iteration() {
    cin >> n;
    
    int help;
    
    for(int i = 0; i <= 2500; i++)
        heights[i] = 0;
    
    for(int i = 0; i < (2*n-1)*n; i++) {
        cin >> help;
        heights[help]++;
    }
    
    for(int i = 1; i <= 2500; i++)
        if((heights[i]&1) == 1)
            cout << i << " ";
    
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        
        OutCase(tIter);
        
        iteration();
        
        cout << endl;
    }
    
    return 0;
}


