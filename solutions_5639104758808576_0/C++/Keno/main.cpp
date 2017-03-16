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

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("A-small-attempt1.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output.txt", ios::out);
    
    string s;
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int Smax;
        fin >> Smax;
        string P;
        fin >> P;
        
        int totalNum = 0;
        int req = 0;
        
        for (int j = 0; j < Smax; j++) {
            char num = P[j] - 48;
            totalNum += num;
            if (totalNum < (j + 1)) {
                req++;
                totalNum++;
            }
        }
        
        fout << "Case #" << (i+1) << ": " << req << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
