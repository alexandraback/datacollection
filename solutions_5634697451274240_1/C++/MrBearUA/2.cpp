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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/B-large.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/B-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

char S[110];

void iteration() {
    cin >> S;
    
    int count = 0;
    
    char current = S[0];
    for(int i = 1; S[i] != 0; i++)
        if(S[i] != current)
        {
            current = S[i];
            count++;
        }
    if(current == '-')
        count++;
    
    cout << count;
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


