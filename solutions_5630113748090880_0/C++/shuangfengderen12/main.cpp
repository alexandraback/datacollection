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
const string FILENAME = "B-small-attempt0";

void missingArr(ifstream & fin, ofstream & fout, int m, int caseID) {
    int heights[2501] = {0};
    int n = 0;
    for (int i = 0; i < 2*m -1; i++) {
        for (int z = 0; z < m; z++) {
            fin >> n;
            heights[n] ++;
        }
    }
    vector<int> res;
    for (int i = 0; i <= 2500; i++) {
        if (heights[i] % 2) res.push_back(i);
    }
    sort(res.begin(), res.end());
    fout << "Case #" << caseID+1 << ": ";
    for (int j = 0; j < m; j++) fout << res[j] << ' ';
    fout << '\n';
}

int main() {
    int n = 0;
    ifstream fin (FILENAME+ ".in");
    ofstream fout (FILENAME + ".out");
    
    if (fin.is_open()){
        fin >> n;
        int m = 0;
        for (int i = 0; i < n; i++) {
            fin >> m;
            missingArr(fin, fout, m, i);
        }
        fin.close();
        fout.close();
    }
    
}
