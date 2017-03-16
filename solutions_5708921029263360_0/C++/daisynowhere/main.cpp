//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int map[100][100];

int main() {
    int T;
    int J, P, S, K;
    int all;
    freopen("/Users/daisy/Documents/GCJ/C-small-attempt0.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/2.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> J >> P >> S >> K;
        cout << "Case #"<< i << ": ";
        if (S <= K) {
            all = J * P * S;
            cout << all << endl;
            for (int j = 1; j <= J; ++j) {
                for (int p = 1; p <= P; ++p) {
                    for (int s = 1; s <= S; ++s) {
                        cout << j << " " << p << " " << s << endl;
                    }
                }
            }
        }
        else {
            all = J * P * K;
            cout << all << endl;
            for (int j = 1; j <= J; ++j) {
                for (int p = 1; p <= P; ++p) {
                    for (int s = 1; s <= K; ++s) {
                        if(!all) break;
                        cout << j << " " << p << " " << s << endl;
                        all --;
                    }
                }
            }
        }
        
    }
    return 0;
}
