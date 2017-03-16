/*
 * PID: 	a
 * NAME:	A
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <climits>

#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <utility>

using namespace std;


// Google Code Jam - specific template

int main(){
    double prob[100000];

	int ncase;
    cin >> ncase;
    for (int i = 0; i < ncase; i++){
        // READ AND PROCESS CASE
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < a; j++){
            cin >> prob[j];
        }

        // calculate the enter right away prob
        double enter = 2.0 + b;
        // calculate the backspace back to beginning
        double back = a + b + 1.0;
        
        // store minimum
        double m = min(enter,back);

        for (int j = 0; j < a; j++){
            // expected keystrokes from j backspaces
            double probCorr = 1.0;
            for (int k = 0; k < a - j; k++){
                probCorr *= prob[k];
            }
            double val = probCorr * (2.0*j + b - a + 1) + (1-probCorr) * (2.0 *j + b -a + 2.0 + b);
            if (val < m) m = val;
        }




        printf("Case #%i: %.6f\n",i+1, m);
        // PRINT CASE RESULTS
        
    }

}
