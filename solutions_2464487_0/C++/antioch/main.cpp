//
//  main.cpp
//  rings
//
//  Created by John Scholes on 27/04/2013.
//  Copyright (c) 2013 John Scholes. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    int r, t, k1;
    float k;
    for(int T1=1; T1<=T; T1++) {
        cin >> r >> t;
        k=(-2*r+1+sqrt((2*r-1)*(2*r-1)+8*t))/4;
        k1=(int)k;
        while(k1*(2*r-1+2*k1)<=t) k1++;
        cout << "Case #" << T1 << ": " << --k1 << "\n";
    }
    return 0;
}

