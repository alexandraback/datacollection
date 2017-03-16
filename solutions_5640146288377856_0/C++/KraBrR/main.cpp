//
//  main.cpp
//  CodeJam2015_3_A
//
//  Created by Nataphol Baramichai on 5/10/2558 BE.
//  Copyright (c) 2558 krabrr. All rights reserved.
//

#include <iostream>

using namespace std;

bool debug = false;

int main() {
    int n;
    cin >> n;
    
    int caseIndex = 1;
    
    for (int i = 0; i < n; i++) {
        int r, c, w;
        cin >> r >> c >> w;
        int count = 0;
        for (int i = 0; i < c; i += w) {
            count++;
        }
        
        if (debug) {
            cout << "count: " << count << endl;
        }
        
        count *= r;
        count += w-1;
        
        //Case #1: 3
        cout << "Case #" << caseIndex << ": " << count;
        if (i != n-1) {
            cout << endl;
        }
        
        caseIndex++;
    }
    
    return 0;
}
