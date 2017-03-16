/* 
 * File:   NOmino.cpp
 * Author: Uday Kandpal
 *
 * Created on 11 April, 2015, 4:43 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

int dom2[4][4] = {
    {0, 1, 0, 1},
    {1, 1, 1, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 1}
};

int dom3[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 1, 1},
    {0, 0, 1, 0}
};

int dom4[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 1}
};

void winPrint(int test, int what) {
    if (what == 1)
        cout << "Case #" << test << ": " << "GABRIEL" << endl;
    else
        cout << "Case #" << test << ": " << "RICHARD" << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int t, caseNo = 1;
    
    freopen("D-small-attempt2.in", "r+", stdin);
    freopen("nomino.txt", "w+", stdout);

    cin>>t;
    while (t--) {
        int x, r, c;
        cin >> x >> r>>c;
        if (x == 1) {
            winPrint(caseNo, 1);
        } else if (x == 2) {
            winPrint(caseNo, dom2[r - 1][c - 1]);
        } else if (x == 3) {
            winPrint(caseNo, dom3[r - 1][c - 1]);
        } else if (x == 4) {
            winPrint(caseNo, dom4[r - 1][c - 1]);
        }
        caseNo++;
    }
    return 0;
}

