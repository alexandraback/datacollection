//
//  main.cpp
//  Codejam
//
//  Created by Mahesh Sharma on 4/10/15.
//  Copyright (c) 2015 Mahesh Sharma. All rights reserved.
//

#include<iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);
    
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int s;
        cin>>s;
        string arr;
        cin>>arr;
        int sum = 0, ans = 0;
        for(int j = 0; j < arr.size(); j++) {
            ans += max(0, j - sum);
            sum +=  max(0, j - sum) + arr[j] - '0';
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
}
