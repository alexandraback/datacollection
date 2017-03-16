//
//  main.cpp
//  codejam
//
//  Created by Silas on 2016. 5. 8..
//  Copyright © 2016년 Silas. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    
    for (int ti = 1; ti <= tc; ti++) {
        long long int b, m;
        cin >> b >> m;
        long long int pow = 1;
        for (int i = 1; i <= b - 2; i++) {
            pow *= 2;
        }
        if (m > pow) {
            printf("Case #%d: IMPOSSIBLE\n", ti);
        }
        else if (m == pow) {
            printf("Case #%d: POSSIBLE\n", ti);
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << 0;
                }
                for (int j = 1; j <= b - i; j++) {
                    cout << 1;
                }
                cout << endl;
            }
            
        }
        else { // m < pow
            printf("Case #%d: POSSIBLE\n", ti);
            if (b == 2 && m == 1) {
                cout << 01 << endl << 00 << endl;
            }
            else {

                // 0
                cout << 0;
                for (int i = 2; i <= b - 1; i++) {
                    cout << 1;
                }
                cout << 0 << endl;
                // other
                for (int i = 2; i <= b - 1; i++) {
                    for (int j = 0; j < i; j++)
                        cout << 0;
                    for (int j = 0; j < b - i - 1; j++)
                        cout << 1;
                
                    if ((1ll << (i - 2)) & m) {
                        cout << 1;
                    }
                    else {
                        cout << 0;
                    }
                    cout << endl;
                }
                for (int i = 0; i < b; i++) {
                    cout << 0;
                
                }
                cout << endl;
            }
        }
    }
}