//
//  main.cpp
//  GCJ
//
//  Created by Keno on 2015/04/11.
//  Copyright (c) 2015年 Keno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("D-large.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-D-l.txt", ios::out);
    
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int X, R, C;
        fin >> X;
        fin >> R;
        fin >> C;
        
        bool rWin = false;
        
        if (X == 2) {
            rWin = ((R * C) % X > 0);
        } else if (X < 7) {
            int halfX = X / 2;
            rWin = ((R * C) % X > 0) || R <= halfX || C <= halfX;
        } else {
            rWin = true;
        }
        
        fout << "Case #" << (i+1) << ": " << (rWin ? "RICHARD" : "GABRIEL") << endl;
        cout << "Case #" << (i+1) << ": " << (rWin ? "RICHARD" : "GABRIEL") << "(" << X <<", " << R << " x " << C << ")" << endl;
        
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
