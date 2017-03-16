//
//  d.cpp
//  CodeJam16
//
//  Created by Ahmed Mohammed on 4/9/16.
//  Copyright © 2016 Akhmed. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;


typedef uint32_t u32;
typedef uint64_t u64;


static u64 interpretInBase(vector<int> const &digs, int base)
{
    u64 result = 0;
    for (int i = (int)digs.size() - 1; i >= 0; i--)
    {
        result *= base;
        result += digs[i];
    }
    return result;
}

int main(int argc, const char * argv[])
{
    if (argc < 3) { printf("Usage: %s <input file> <output file>\n", argv[0]); exit(1);}
    
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open()) { printf("Unable to open input file\n"); exit(1);}
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open()) { printf("Unable to open output file\n"); exit(1);}
    fout.seekp(0);
    
    fout.precision(7);
    fout.setf(ios::fixed);
    
    
    // solve cases
    uint64_t testcase_count;
    fin >> testcase_count;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        fout << "Case #" << (tcase + 1) << ":";
        
        int K, C, S; fin >> K >> C >> S;
        
        if (C * S < K) fout << " IMPOSSIBLE" << endl;
        else
        {
            for (int k = 0; k < K; k += C)
            {
                vector<int> digs;
                for (int i = k; i < (k + C); i++) digs.insert(digs.begin(), (i % K));
                fout << ' ' << interpretInBase(digs, K) + 1;
            }
            fout << endl;
        }
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}