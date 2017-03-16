//
//  main.cpp
//  Google Code Jam
//
//  Created by xiaoxin ren on 4/8/16.
//  Copyright © 2016 xiaoxin ren. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <bitset>
#include <gmp.h> // Added dymanic library.
using namespace std;
const string FILENAME = "A-small-attempt0";

string lastword(string & s) {
    int n = (int)s.size();
    string res = "";
    res += s[0];
    for(int i = 1; i< n; i++) {
        if (s[i] >= res[0]) res = s[i]+ res;
        else res = res + s[i];
        cout << res << '\n';
    }
    return res;
    
}

int main() {
    int n = 0;
    ifstream fin (FILENAME+ ".in");
    ofstream fout (FILENAME + ".out");
    
    if (fin.is_open()){
        fin >> n;
        string s = "";
        for (int i = 0; i < n; i++) {
            fin >> s;
            // fout << num << '\n';
            fout << "Case #" << i+1 << ": " << lastword(s)<< '\n';
        }
        fin.close();
        fout.close();
    }
    
}
