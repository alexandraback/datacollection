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

#define IN_NAME ("/Users/andriymedvid/Downloads/C-small-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/C-small-attempt0.out")

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
    bool sum[35];
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        for(int i = 0; i < 35; i++)
            sum[i] = false;
        
        sum[0] = true;
        
        cin >> c >> d >> v;
        
        for(int i = 0; i < d; i++)
            cin >> nominals[i];
        
        sort(nominals, nominals + d);
        
        for(int i = 0; i < d; i++)
            for(int j = v - nominals[i]; j >= 0; j--)
                if(sum[j])
                    sum[j + nominals[i]] = true;
        
        
        int result = 0;
        
        for(int i = 1; i <= v; i++) {
            if(sum[i] == false)
            {
                result++;
                for(int j = v - i; j >= 0; j--)
                    if(sum[j])
                        sum[j+i] = true;
            }
        }
        
        OutCase(tIter);
        // out answer
        
        cout << result;
        
        cout << endl;
    }
    
    return 0;
}

