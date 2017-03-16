/*
* File:   main.cpp
* Author: Ming Qin
*
* Created on February 27, 2015, 8:37 PM
*/

//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}

int solve(int r,int c,int w) {
    int res;
    res = c / w * r + ( w - 1 );
    if (c%w !=0 && w>1) {
        res++;
    }
    return res;
}

int main() {
    long long nCase;
    fstream fin("1.in");
    ofstream fout("out.txt");

    int r,c,w;

    fin >> nCase;
    for (long long caseID = 1; caseID <= nCase; ++caseID) {
        fin >> r >> c >> w;


        fout << "Case #" << caseID << ": " << solve(r,c,w) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
