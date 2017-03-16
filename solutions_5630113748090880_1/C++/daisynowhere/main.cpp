//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <string>
using namespace std;

int main() {
    int T, N, now;  //num of Test
    set<int> S;
    set<int>::iterator si;
    freopen("/Users/daisy/Documents/B-large.in","r",stdin);
    freopen("/Users/daisy/Documents/B-large.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        S.clear();
        for (int j = 1; j <= (2*N-1)*N; ++j) {
            cin >> now;
            if (S.count(now)) {
                S.erase(S.find(now));
            }
            else
                S.insert(now);
        }
        printf("Case #%d:", i);
        for (si=S.begin(); si!=S.end(); si++)
            cout << " " << *si;
        
        cout << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
