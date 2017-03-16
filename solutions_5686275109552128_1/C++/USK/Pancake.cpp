/* 
 * File:   Pancake.cpp
 * Author: Uday Kandpal
 *
 * Created on 12 April, 2015, 12:59 AM
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b ? a : b);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int t, caseNo = 1;
    freopen("B-large.in", "r+", stdin);
    freopen("pancakeLarge.txt", "w+", stdout);
    cin>>t;
    while (t--) {
        int d, p[1001];

        cin>>d;
        for (int i = 0; i < d; i++) {
            cin >> p[i];
        }
        //calculate maximum time
        int maxTime = p[0];
        for (int i = 1; i < d; i++) {
            if (maxTime < p[i]) {
                maxTime = p[i];
            }
        }
        // maximum time that can be taken = maxValue
        int globalMinTime = maxTime;
        int localMinTime;
        for (int time = 1; time <= maxTime; time++) {
            localMinTime = time;
            for (int iteration = 0; iteration < d; iteration++) {
                localMinTime += p[iteration] / time;
                if (p[iteration] % time == 0) {
                    localMinTime--; //number of count is one less than actual value
                }
            }
            globalMinTime = min(globalMinTime, localMinTime);
        }

        cout << "Case #" << caseNo << ": " << globalMinTime << endl;
        caseNo++;
    }
    return 0;
}

