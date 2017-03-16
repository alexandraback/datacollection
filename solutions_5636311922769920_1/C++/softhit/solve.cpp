//
// Created by mark on 4/8/16.
//
#include "includes.h"
#include <vector>
#include <iterator>
#include <algorithm>

int solve(int num) {
    int K,C,S;
    cin >> K >> C >> S;
    if(C==1){
        if (S == K) {
            for ( int j =0; j< S ; ++j) {
                cout << j+1 << " " ;
            }
        } else {
            cout << "IMPOSSIBLE" ;
        }
    } else if ( K ==1) {
        cout << 1;
    } else {
        if (S >= K -1) {
            for ( int j = 1; j< S; ++j) {
                cout << j+1 << " " ;
            }
        }
        else {
            cout << "IMPOSSIBLE" ;
        }

    }
    cout << endl;
    return 0;
}