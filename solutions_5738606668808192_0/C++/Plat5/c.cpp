//
//  c.cpp
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

#include <gmp.h>

using namespace std;


typedef uint32_t u32;
typedef uint64_t u64;



static void interpretInBase(u32 n, int base, mpz_t &result)
{
    mpz_set_ui(result, 0);
    for (int i = 31; i >= 0; i--)
    {
        mpz_mul_ui(result, result, base);
        if (n & (1 << i)) mpz_add_ui(result, result, 1);
    }
}


static int primes[] = { 2, 3, 5, 7 };


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
        fout << "Case #" << (tcase + 1) << ":" << endl;
        
        int N, J; fin >> N >> J;
        
        mpz_t n, r;
        mpz_inits(n, r, NULL);
        
        int resultCount = 0;
        for (u32 i = (1 << (N-1)) + 1; i && ((1ULL << N) > i); i += 2)
        {
            int divisors[11];
            
            bool fail = true;
            for (int b = 2; b <= 10; b++)
            {
                interpretInBase((u32)i, b, n);
                
                // find a small divisor
                bool found = false;
                for (int pi = 0; pi < 4; pi++)
                {
                    int const p = primes[pi];
                    if (0 == mpz_mod_ui(r, n, p))
                    {
                        divisors[b] = p;
                        found = true;
                        break;
                    }
                }
                
                fail = (false == found);
                if (fail) break;
            }
            
            if (false == fail)
            {
                char str[100]; mpz_get_str(str, 10, n); fout << str;
                for (int b = 2; b <= 10; b++) fout << ' ' << divisors[b];
                
                if (++resultCount == J) break;
                fout << endl;
                
            }
        }
        
        assert(resultCount == J);
        
        mpz_clears(n, r, NULL);
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}

