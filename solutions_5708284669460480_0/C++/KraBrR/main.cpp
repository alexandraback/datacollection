//
//  main.cpp
//  CodeJam2015_3_B
//
//  Created by Nataphol Baramichai on 5/10/2558 BE.
//  Copyright (c) 2558 krabrr. All rights reserved.
//

#include <map>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

bool debug = false;
bool debug_detail = false;

int main() {
    int n;
    cin >> n;
    
    int caseIndex = 1;
    
    for (int i = 0; i < n; i++) {
        int k, l, s;
        cin >> k >> l >> s;
        
        string key, target;
        cin >> key >> target;
        
        map<char, int> keyMap;
        for (int j = 0; j < key.length(); j++) {
            keyMap[key[j]]++;
        }
        
        if (debug) {
            cout << "k: " << k << " l: " << l << " s: " << s << endl;
            cout << "key: " << key << endl;
            cout << "target: " << target << endl;
        }
    
        bool valid = true;
        for (int j = 0; j < target.length(); j++) {
            if (keyMap[target[j]] == 0) {
                valid = false;
            }
        }
        
        double ans;
        
        if (valid) {
            int stack = 0;
            if (target.length() > 1 && target[0] == target[target.length()-1]) {
                stack = 1;
            }
            
            char first = target[0];
            bool all_same = true;
            for (int j = 0; j < target.length(); j++) {
                if (target[j] != first) {
                    all_same = false;
                    break;
                }
            }
            
            if (all_same) {
                stack = l-1;
            }
            
            if (debug) {
                cout << "stack: " << stack << endl;
            }
            
            double avg_pos = 1.0;
            double prep_banana = 0;
            if (stack > 0) {
                int c_count = l;
                prep_banana = 1;
                for (int j = 0; j < 1000; j++) {
                    c_count += l-stack;
                    if (debug_detail) {
                        cout << "count: " << c_count << endl;
                    }
                    if (c_count > s) {
                        break;
                    }
                    prep_banana++;
                }
            }
            else {
                prep_banana = (int) s/l;
            }
            
            for (int j = 0; j < target.length(); j++) {
                avg_pos *= (double) keyMap[target[j]]/k;
            }
            
            avg_pos *= prep_banana;
            
            ans = prep_banana-avg_pos;
            if (debug) {
                cout << "prep: " << prep_banana << ", pos: " << avg_pos << endl;
            }
        }
        else {
            ans = 0;
        }
        
        printf("Case #%d: %.10f", caseIndex, ans);
        if (i != n-1) {
            printf("\n");
        }
        
        caseIndex++;
    }
    return 0;
}
