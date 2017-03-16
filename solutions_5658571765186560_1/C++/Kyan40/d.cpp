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

ifstream fin("D-large.in");
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
        if (R > C) swap(R, C);
        if (X >= 7) ans = "RICHARD";
        else if ((R*C) % X) ans = "RICHARD";
        else if (((int)(X+1)/2) > min(R, C)) ans = "RICHARD";
        else if (X > max(R, C)) ans = "RICHARD";
        else if (X > R && X > C) ans = "RICHARD";
        else if (X == 4 && R == 2) ans = "RICHARD";
        else if (X == 5 && R == 3 && C == 5) ans = "RICHARD";
        else if (X == 6 && R == 3) ans = "RICHARD";
        else ans = "GABRIEL";
        fout << "Case #" << ti << ": " << ans << endl;
    }
}
