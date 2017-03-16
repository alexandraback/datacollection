/* 
 * File:   SO.cpp
 * Author: Uday Kandpal
 *
 * Created on 11 April, 2015, 9:08 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int t, caseNo = 1;
    freopen("A-large.in", "r+", stdin);
    freopen("out.txt", "w+", stdout);

    cin>>t;
    while (t--) {
        int smax, sum[1002], r[1002];
        char n[1002];
        cin >> smax>>n;
        r[0] = 0;
        sum[0] = (n[0] - '0');
        for (int i = 1; i <= smax; i++) {
            int diff = i - (r[i - 1] + sum[i - 1]);
            if (diff > 0) {
                r[i] = r[i - 1] + diff;
            } else {
                r[i] = r[i - 1];
            }
            sum[i] = sum[i - 1] + (n[i] - '0');
        }
        cout << "Case #" << caseNo << ": " << r[smax] << endl;
        caseNo++;
    }
    return 0;
}

