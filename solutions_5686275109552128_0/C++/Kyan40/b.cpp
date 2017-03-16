//
//  b.cpp
//
//
//  Created by Nikifor Zhao on 15/4/11.
//
//

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("B-small-attempt1.in");
ofstream fout("output.txt");

int main() {
    int T, D, ans, lmax;
    fin >> T;
    for (int ti = 1; ti <= T; ti ++) {
        fin >> D;
        ans = 0; lmax = 0;
        for (int i = 0; i < D; i ++) {
            int temp, ta;
            fin >> temp;
            ta = ((temp+1)/2-1);
            lmax = max(lmax, temp-2*ta);
            if (ta) lmax = 2;
            ans += ta;
        }
        ans += lmax;
        fout << "Case #" << ti << ": " << ans << endl;
    }
}
