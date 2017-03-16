//
//  main.cpp
//  codejam20141A
//
//  Created by Boychuk, Petro on 4/25/14.
//  Copyright (c) 2014 Boychuk, Petro. All rights reserved.
//

#include <iostream>
#include<vector>
#include<string>

using namespace std;

int n,l;

long long int gcd (long long n1,long long n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

void solve() {
    unsigned long long p,q;
    scanf("%llu/%llu", &p, &q);
    long long d = gcd(p, q);
    
//    cout << p << " " << q;
    
    p = p / d;
    q = q / d;
    
//    cout << p << " " << q;
    
    long long qq = q;
    int cnt = 0;
    while (qq) {
        if(qq % 2 == 1)
            cnt++;
        qq >>= 1;
    }
    
    
    if(cnt != 1) {
        cout << "impossible";
    } else {
        int res = 1;
        while (q > 2 * p && q > 0) {
            q /= 2;
            res++;
        }
        cout << res;
    }
    
}


int main(int argc, const char * argv[])
{
    
    freopen("inA", "r", stdin);
    freopen("outA", "w", stdout);
    
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
    
    return 0;
}

