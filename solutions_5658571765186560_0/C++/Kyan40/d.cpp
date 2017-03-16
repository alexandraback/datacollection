//
//  d.cpp
//
//
//  Created by Nikifor Zhao on 15/4/11.
//
//

#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("D-small-attempt3.in");
ofstream fout("output.txt");

int f[4][4][4] = {
    {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
    },
    
    {
    {1, 0, 1, 0},
    {0, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 0, 0, 0}
    },
    
    {
    {1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 0, 0, 0},
    {1, 1, 0, 1}
    },
    
    {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 0},
    {1, 1, 0, 0}
    }
};
int main() {
    int T, X, R, C;
    string ans;
    fin >> T;
    for (int ti = 1; ti <= T; ti ++) {
        fin >> X >> R >> C;
        if (f[X-1][R-1][C-1]) ans = "RICHARD";
        else ans = "GABRIEL";
        fout << "Case #" << ti << ": " << ans << endl;
    }
}
