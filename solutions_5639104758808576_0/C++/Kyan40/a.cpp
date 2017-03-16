//
//  a.cpp
//  
//
//  Created by Nikifor Zhao on 15/4/11.
//
//

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("output.txt");

int main() {
    int T, smax, cnt, ans;
    char c[2000];
    fin >> T;
    for (int ti = 1; ti <= T; ti ++) {
        fin >> smax >> c;
        cnt = 0; ans = 0;
        for (int i = 0; i <= smax; i ++) {
            ans = max(i - cnt, ans);
            cnt += (int)(c[i] -  48);
        }
        fout << "Case #" << ti << ": " << ans << endl;
    }
}
