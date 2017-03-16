//
//  main.cpp
//  abcd
//
//  Created by cyanic MayDay on 12-4-14.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//


#include<iostream>
using namespace std;
#include <vector>


int main()
{
	freopen("/Users/ccyanic/Downloads/A-small-attempt3.in.txt", "r", stdin);
    freopen("/Users/ccyanic/Downloads/A-small-attempt3.out.txt", "w", stdout);
    int T = 0;
    int n = 0;
    int temp , sum = 0, dele;
    vector<int> m;
    scanf("%d", &T);
    for (int i = 0; i < T; i ++) {
        sum = 0;
        dele = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j ++) {
            scanf("%d", &temp);
            m.push_back(temp);
            sum += temp;
        }
        printf("Case #%d: ", i + 1);
        int doublesum = sum * 2;
        for (int j = 0; j < n; j ++) {
            if ((double)sum * 2 / n - m[j] <= 0) {
                dele ++;
                doublesum -= m[j];
            }
        }
        int new_n = n - dele;
        for (int j = 0; j < n; j ++) {
            double out = ((double)doublesum / new_n - m[j] ) / (double)sum;
            if (out >= 0) {
                printf("%.6lf ", out * 100);
            }
            else {
                printf("%.6lf ", 0.0 * 100);
            }
            
        }
        m.clear();
        cout << endl;
    }
	return 0;
}


