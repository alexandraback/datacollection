//
//  main.cpp
//  ManageYourEnergy
//
//  Created by Ahmed Mohammed Abdurahman on 4/27/13.
//  Copyright (c) 2013 Better MDM LLC. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


uint64_t maxval(uint64_t n, int *v, uint64_t t, uint64_t E, uint64_t e, uint64_t r)
{
    if (t >= n) return 0;
    
    uint64_t max = 0;
    uint64_t value = 0;
    for (uint64_t i = 0; i <= e; i++, value += v[t])
    {
        uint64_t nexte = e - i + r;
        if (nexte > E) nexte = E;
        
        uint64_t temp = maxval(n, v, t + 1, E, nexte, r);
        temp += value;
        if (temp > max) max = temp;
    }
    
    return max;
}


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
        uint64_t e, r, n;
        fin >> e >> r >> n;
        
        int v[n];
        for (int i = 0; i < n; i++)
            fin >> v[i];
        
        
        fout << "Case #" << (tcase + 1) << ": " << maxval(n, v, 0, e, e, r) << endl;
    }
    
    
    
    fin.close();
    fout.close();
    
    return 0;
}