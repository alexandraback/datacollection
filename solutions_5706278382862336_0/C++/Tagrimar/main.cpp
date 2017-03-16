//
//  main.cpp
//  Codeforces
//
//  Created by Taygrim on 20.03.13.
//  Copyright (c) 2013 Taygrim. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long gcd(long long a, long long b) {
    while(a && b) {
        if(a > b)
            a%=b;
        else
            b%=a;
    }
    return a + b;
}

bool pow(long long a) {
    while(!(a % 2))
        a/=2;
    return !(a - 1);
}

int main()
{
    ifstream cin("A-small-attempt0.in.txt");
    ofstream cout("A-small-attempt0.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++) {
        long long a, b;
        char c;
        cin >> a >> c >> b;
        long long temp = gcd(a, b);
        a /= temp;
        b /= temp;
        cout << "Case #" << q + 1 << ": ";
        
        if(!pow(b))
            cout << "impossible";
        else {
            int res = 0;
            while(a < b) {
                b /= 2;
                res++;
            }
            cout << res;
        }
        
        cout << "\n";
    }
}