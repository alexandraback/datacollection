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
using namespace std;

int main() {
    int T;  //num of Test
    int N;
    int t, k;
    bool full, num[10];
    freopen("/Users/daisy/Documents/GCJ/GCJ/A-large.in","r",stdin);
    freopen("/Users/daisy/Documents/GCJ/GCJ/A-large.out","w",stdout);
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        k = 0;
        full = false;
        for (int j = 0; j < 10; j++) {
            num[j] = false;
        }
        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", i);
        }else{
            while (!full) {
                k++;
                t = k*N;
                while (t) {
                    num[t%10] = true;
                    t /= 10;
                }
                full = true;
                for (int j = 0; j < 10 ; j++) {
                    full &= num[j];
                }
            }
            printf("Case #%d: %d\n", i, k*N);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
