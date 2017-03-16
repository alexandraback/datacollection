//
//  main.cpp
//  Pogo
//
//  Created by Ahmed Mohammed Abdurahman on 5/12/13.
//  Copyright (c) 2013 Better MDM LLC. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main(int argc, const char * argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    
    // open files
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open())
    {
        printf("Unable to open input file\n");
        exit(1);
    }
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open())
    {
        printf("Unable to open output file\n");
        exit(1);
    }
    fout.seekp(0);
    
    
    
    // solve test cases
    uint64_t testcase_count;
    fin >> testcase_count;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        int64_t x, y;
        fin >> x >> y;
        
        char xf, xb, yf, yb;
        if (x < 0) {
            xf = 'W';
            xb = 'E';
            
            x = -x;
        }
        else {
            xf = 'E';
            xb = 'W';
        }
        
        if (y < 0) {
            yf = 'S';
            yb = 'N';
            
            y = -y;
        }
        else {
            yf = 'N';
            yb = 'S';
        }
        
        
        fout << "Case #" << (tcase + 1) << ": ";
        for (uint64_t i = 0; i < x; i++) fout << xb << xf;
        for (uint64_t i = 0; i < y; i++) fout << yb << yf;
        fout << endl;
    }
    
    
    
    fin.close();
    fout.close();
    
    return 0;
}