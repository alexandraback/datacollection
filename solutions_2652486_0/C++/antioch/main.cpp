//
//  main.cpp
//  luck
//
//  Created by John Scholes on 27/04/2013.
//  Copyright (c) 2013 John Scholes. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int T; cin >> T;
    int R, N, M, K, i, maxp, temp, j, key;
    int ans[20]={222,223,224,225,233,244,255,234,235,245,333,334,335,344,355,345,444,445,455,555};
    cin >> R >> N >> M >> K;
    cout << "Case #1:\n";
    for(i=0; i<R; i++) {
        maxp=1;
        for(j=0; j<K; j++) {
            cin >> temp;
            if(temp>maxp) maxp=temp;
        }
        switch(maxp) {
            case 8: key=0; break;
            case 12: key=1; break;
            case 16: key=2; break;
            case 20: key=3; break;
            case 18: key=4; break;
            case 32: key=5; break;
            case 50: key=6; break;
            case 24: key=7; break;
            case 30: key=8; break;
            case 40: key=9; break;
            case 27: key=10; break;
            case 36: key=11; break;
            case 45: key=12; break;
            case 48: key=13; break;
            case 75: key=14; break;
            case 60: key=15; break;
            case 64: key=16; break;
            case 80: key=17; break;
            case 100: key=18; break;
            case 125: key=19; break;
            default: key=0;
        }
        cout << ans[key] <<  "\n";
    }
    return 0;
}

