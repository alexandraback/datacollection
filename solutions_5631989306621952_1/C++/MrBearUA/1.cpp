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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/A-large.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/A-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

char str[1010];
char res[2010];

void iteration() {
    
    cin >> str;
    
    int startpos = 1000;
    int endPos = 1000;
    
    res[1000] = str[0];
    
    for(int i = 1; str[i]; i++) {
        if(str[i] >= res[startpos]) {
            startpos--;
            res[startpos] = str[i];
        } else {
            endPos++;
            res[endPos] = str[i];
        }
    }
    
    for(int i = startpos; i <= endPos; i++)
        cout << res[i];
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


