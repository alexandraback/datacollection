//
//  main.cpp
//  GCJ
//
//  Created by 陶源 on 4/9/16.
//  Copyright © 2016 daisynowhere. All rights reserved.
//

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int T;  //num of Test
    int N, J, k, t;
    freopen("/Users/daisy/Documents/GCJ/GCJ/C-small-attempt0.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/C-small-attempt0.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N >> J;
        printf("Case #%d:\n", i);
        k = 0;
        while (J--) {
            cout <<"11";
            t = k;
            for (int j = 0; j < N-4; ++j) {
                if( t%2 == 0 ){
                    cout << "0";
                } else{
                    cout << "11";
                    j++;
                }
                t /= 2;
            }
            cout << "11";
            k++;
            cout << " 3 4 5 6 7 8 9 10 11"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
