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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/D-small-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/D-small-attempt0.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

long basis, power, cnt;

void iteration() {
    cin >> basis >> power >> cnt;
    
    if(power*cnt < basis) {
        cout << "IMPOSSIBLE";
        return;
    }
    
    for(int i = 0; i < basis; i+=power) {
        long res = 0;
        for(int j = i; j < basis && j < i+power; j++)
            res = res*basis + j;
        cout << res+1 << " ";
    }
    
    
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


