//
//  main.cpp
//  gcj1cb
//
//  Created by eycia on 16/5/8.
//  Copyright © 2016年 eycia. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int mat[55][55];

void work() {
    memset(mat, 0, sizeof(mat));
    
    long long b, m;
    cin >> b >> m;

    if (m > (long long)(1 << (b-2))) {
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("POSSIBLE\n");

    
    stack<int> s;
    
    if (m == (long long)(1 << (b-2))) {
        s.push(1);
        m--;
    } else {
        s.push(0);
    }
    
    long long tmp = m;
    
    for (int i = 0; i < b-2; i++) {
        s.push(tmp%2);
        tmp /= 2;
    }
    s.push(0);
    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    
    for (int i = 1; i < b; i++) {
        for (int j = 0; j < b; j++) {
            if (i >= j) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/eycia/Downloads/B-small-attempt0 (1).in", "r", stdin);
    freopen("/Users/eycia/Desktop/oo", "w", stdout);
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        work();
    }
}
