//
//  main.cpp
//  B1
//
//  Created by wangdongfang on 15/5/2.
//  Copyright (c) 2015年 _. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//cout << "Case #" << round << ": ";

int N;

int num[100000000];

void find(int round) {
    
    num[0] = 0;
    num[1] = 1;
    
    for (int i = 1; i <= N; i++) {
        int reverse = 0;
        int tmp = i;
        int b = -1;
        while (tmp > 0) {
     
            if (tmp % 10 >= 0 )b++;
            tmp /= 10;
        }
        tmp = i;
    //    cout << "i : " << i << " b " << b << endl;
        while (tmp > 0 && b >= 0) {
            reverse += tmp % 10 * (int)pow(10, b);
            b--;
            tmp /= 10;
        }
 //       cout << "i: " << i << " reveerse " << reverse << endl;
        num[i] = num[i] < num[i - 1] + 1 ? num[i] : num[i - 1] + 1;
        
//        cout << "i : " << i << " num " << num[i] << endl;

 //       if (reverse > i){
            if (num[reverse] > num[i] + 1)num[reverse] = num[i] + 1;
 //           cout << "reverse : " << reverse << " num " << num[reverse] << endl;
  //      }
        
        
    }
    cout << "Case #" << round << ": "<< num[N] << endl;
}

int main() {
 
 //   freopen("/Users/wangdongfang/Myprogram/codejam2015/round1B/B1/B1/sampledata", "r", stdin);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        for (int j = 0; j <= N; j++) {
            num[j] = 1000000000;
        }
        find(i);
    }
  
    
    return 0;
}
