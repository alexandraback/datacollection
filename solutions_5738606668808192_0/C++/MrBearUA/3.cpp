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

#define MAX_NUM 2000//40000000

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/3.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Qual_2016/3.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}
int N;
int J;


void iteration() {
    cin >> N;
    cin >> J;
    
    
    for(int j = 0; j < J; j++) {
        
        cout << endl << "1";
        
        for(int i = 0; i < (N/2-1); i++) {
            if((j & (1 << i)) == 0)
                cout << "00";
            else
                cout << "11";
        }
        
        cout << "1 3 2 5 2 7 2 3 2 11";
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


