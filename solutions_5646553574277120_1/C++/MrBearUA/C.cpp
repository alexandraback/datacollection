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

#define IN_NAME ("/Users/andriymedvid/Downloads/C-large-test.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/C-large-test.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    int c,d,v;
    int nominals[10];
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        cin >> c >> d >> v;
        
        for(int i = 0; i < d; i++)
            cin >> nominals[i];
        
        sort(nominals, nominals + d);
        
        int sum = 0;
        int result = 0;
        int pointer = 0;
        
        while(sum < v) {
            if(pointer >= d || sum + 1 < nominals[pointer]) {
                result++;
                sum += c*(sum + 1);
            } else {
                sum += c*(nominals[pointer]);
                pointer++;
            }
        }
        
        OutCase(tIter);
        // out answer
        
        cout << result;
        
        cout << endl;
    }
    
    return 0;
}

