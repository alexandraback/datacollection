/* 
 * File:   new_lottery_game.cc
 * Author: vivek
 *
 * Created on May 3, 2014, 9:47 PM
 */

#include <cstdlib>

#include <iostream>
#include <cstdio>


#include <vector>
#include <set>
#include <algorithm>
#include <map>

#include <cmath>



using namespace std;
#define Int long int
#define UInt unsigned Int 

/*
 * 
 */
int main(int argc, char** argv) {
    UInt t;
    cin >> t;
    for (UInt i = 1; i <= t; i++) {
        UInt k;
        UInt a, b;
        cin >> a >> b >> k;
        UInt count = 0;
        for (UInt j = 0; j < a; j++) {
            for (UInt l = 0; l < b; l++) {
                if ((l & j) < k) {
                    count++;
                }
            }
        }
        cout << "Case #" << i << ": " << count << endl;
    }
    return 0;
}

