//
//  main2.cpp
//  CodeJam
//
//  Created by Victor Young on 5/8/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int a[27];

long long  myPow(int x, int p)
{
    if (p == 0) return 1;
    if (p == 1) return x;

    long long  tmp = myPow(x, p/2);
    if (p%2 == 0) return tmp * tmp;
    else return x * tmp * tmp;
}

int main(){

    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
        fprintf(stderr,"error redirecting stdout\n");
    if(freopen("/Users/Victor/Desktop/B-small-attempt0.in", "r", stdin) == NULL)
        fprintf(stderr,"error redirecting stdin\n");

    int n;
    cin >>n;
    for (int i = 0; i<n; i++) {
        int B;
        long long M;
        cin >> B >>M;
        if (M>myPow(2, B-2)) {
            cout << "Case #"<<i+1<<": IMPOSSIBLE"<<endl;
        }
        else{
            cout << "Case #"<<i+1<<": POSSIBLE"<<endl;
            int a[100];
            int index = 0;
            while(M/2){
                a[index]=M%2;
                M /=2;
                index ++;
            }
            index++;
            int result[51][51];
            for (int j = 0; j<B; j++) {
                for (int k = 0; k<B; k++) {
                    if (j==k) {
                        result[j][k] = 0;
                    }
                    else if (k==B-1) {
                        result[j][k] = 0;
                    }
                    else if (j>k&&j<=index) {
                        result[j][k] = 1;
                    }
                    else if (j==index+1&&a[k]==1) {
                        result[j][k] = 1;
                    }
                    else if (j==B-1&&k==index-1) {
                        result[j][k] = 1;
                    }
                    else{
                        result[j][k] = 0;
                    }
                }
            }
            for (int j = 0; j<B; j++) {
                for (int k = 0; k<B; k++) {
                    cout << result[k][j
                                      ];
                }
                cout << endl;
            }
            
            
        }
    }
}