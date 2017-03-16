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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/A-large.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/A-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

bool digits[10];
int N = 0;
void iteration() {
    
    memset(digits, 0, 10);
    cin >> N;
    
    for(int multiplier = 1; multiplier <= 90; multiplier++) {
        int number = N*multiplier;
        
        while(number > 0) {
            digits[number%10] = true;
            number /= 10;
        }
        
        bool allDigits = true;
        for(int i = 0; i < 10; i++)
            allDigits = allDigits && digits[i];
        
        if(allDigits) {
            cout << N*multiplier;
            return;
        }
    }
    cout << "INSOMNIA";
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


