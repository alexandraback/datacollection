//
//  a.cpp
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
typedef uint32_t u64;


static u32 foo(u32 n, u32 flags)
{
    if (n) for (; n; n /= 10) flags |= (1U << (n % 10));
    else flags |= 1;
    
    return flags;
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
        u32 N; fin >> N;
        
        if (0 == N)
        {       // N > 0 never results in insomnia
            fout << "Case #" << (tcase + 1) << ": INSOMNIA"  << endl;
            continue;
        }
        
        u32 flags = 0;
        const u32 completeFlags = (1U << 10) - 1;
        
        int i;
        for (i = 1; i < 100; i++)
        {
            flags = foo(i * N, flags);
            if (completeFlags == flags) break;
        }

        assert(i != 100);
        
        fout << "Case #" << (tcase + 1) << ": " << i * N << endl;
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}



