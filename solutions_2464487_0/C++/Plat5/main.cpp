//
//  main.cpp
//  BullsEye
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
        uint64_t r;         // radius of inner most white circle
        int64_t t;          // paint volume
        
        fin >> r >> t;
        uint64_t rs = r;
        
        uint64_t count = 0;
        while (1)
        {
            uint64_t p = rs + rs + 1;
            if (p > t) break;
            
            count++;
            t -= p;
            rs += 2;
        }
        
        
        fout << "Case #" << (tcase + 1) << ": " << count << endl;
    }
    
    
    
    fin.close();
    fout.close();
    
    return 0;
}