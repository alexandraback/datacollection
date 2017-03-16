//
//  main.cpp
//  MinesweeperMaster
//
//  Created by Ahmed Mohammed Abdurahman on 4/12/14.
//  Copyright (c) 2014 Better LLC. All rights reserved.
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
    
    fout.precision(7);
    fout.setf(ios::fixed);
    
    
    // solve test cases
    uint64_t testcase_count;
    fin >> testcase_count;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        if (tcase == 120)
        {
            cout << endl;
        }
        
        int r, c, m;
        fin >> r;
        fin >> c;
        fin >> m;
        
        int a = r * c;
        int s = a - m;
        int d = ceil(sqrt(s));
        
        int rr = d, rc = d;
        if (rr > r) {rr = r; rc = ceil(((double)s) / rr);}
        else if (rc > c) {rc = c; rr = ceil(((double)s) / rc);}
        
        int e = rr * rc - s;
        if (e != 0)
        {
            if (rr >= rc)
            {
                if (e >= rc) { rr--; e -= rc;}
            }
            else
            {
                if (e >= rr) { rc--; e -= rr;}
            }
        }
        
        bool possible = true;
        if (((r - rr) > 0) && (rc > 1)) possible = rr > 1;
        if (possible && ((c - rc) > 0) && (rr > 1)) possible = rc > 1;
        if (possible && (e != 0)) possible = (rr - 2) * (rc - 2) >= e;
        
        fout << "Case #" << (tcase + 1) << ":" << endl;
        
        if (!possible) {fout << "Impossible" << endl; continue;}
        
        
        char mf[r][c];
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mf[i][j] = '*';
        
        for (int i = 0; i < rr; i++)
            for (int j = 0; j < rc; j++)
                mf[i][j] = '.';
        
        int depth = 0;
        while (e > 0)
        {
            int i;
            for (i = 0; (i < e) && (i < rr - (2 + depth)); i++) mf[rr-(1+i+depth)][rc-(1+depth)] = '*';
            e -= i;
            
            int j;
            for (j = 0; (j < e) && (j < rc - (3 + depth)); j++) mf[rr-(1+depth)][rc-(2+j+depth)] = '*';
            e -= j;
            
            depth++;
        }
        
        mf[0][0] = 'c';
        
        for (int i = 0; i < r; i++, fout << endl)
            for (int j = 0; j < c; j++) fout << mf[i][j];
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}

