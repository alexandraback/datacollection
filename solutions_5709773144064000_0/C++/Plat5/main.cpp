//
//  main.cpp
//  CookieClickerAlpha
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
        double c, f, x;
        fin >> c;
        fin >> f;
        fin >> x;
        
        double result;
        
        if (c >= x) result = x / 2.0;
        else
        {
            int n = ceil((f * (x - c) - c - c) / (f * c));
            if (n < 0) n = 0;
//            cout << n << endl;
            
            result = 0.0;
            double rate = 2.0;
            for (int i = 0; i < n; i++)
            {
                result += c / rate;
                rate += f;
            }
            result += x / rate;
        }
        
        fout << "Case #" << (tcase + 1) << ": " << result << endl;
    }
    
    
    fin.close();
    fout.close();
    
    
    
    return 0;
}
