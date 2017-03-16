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

//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B.out")

//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B-large.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B-large.out")

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B-small-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/B-small-attemp0.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

long b, m;

void iteration() {
    
    cin >> b >> m;
    
    long help = m;
    
    long array[65];
    
    bool wasOne = false;
    
    for(int i = 0; i < b-2; i++) {
        array[i] = help&1;
        help /= 2;
        
        if(array[i] == 1)
            wasOne = true;
    }
    
    if(help == 0) {
        cout << "POSSIBLE" << endl;
        
        cout << 0;
        for(int i = 0; i < b-2; i++)
            cout << array[b-3-i];
        cout << 0;
        cout << endl;
        
        for(int j = 1; j < b; j++) {
            for(int i = 0; i < b; i++)
                cout << ((i <= j) ? 0 : 1);
            cout << endl;
        }
    } else if(help == 1 && !wasOne) {
        cout << "POSSIBLE" << endl;
        
        for(int j = 0; j < b; j++) {
            for(int i = 0; i < b; i++)
                cout << ((i <= j) ? 0 : 1);
            cout << endl;
        }
    }
    else {
        cout << "IMPOSSIBLE";
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


