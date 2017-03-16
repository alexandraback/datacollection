//
//  main.cpp
//  DeceitfulWar
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
        int n;
        fin >> n;
        
        vector<double> a(n), b(n);
        for (int i = 0; i < n; i++) fin >> a[i];
        for (int i = 0; i < n; i++) fin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        

        int d = 0;      // Naomi's wins while playing deceitfully
        {
            int c = 0, ai = 0, bi = 0;
            while ((ai < n) && (bi < n))
            {
                if (a[ai] < b[bi])
                {
                    ai++;
                    if (c > 0)
                    {
                        d++;
                        c--;
                    }
                }
                else
                {
                    bi++;
                    c++;
                }
            }
            if (bi == n) d += (n - ai);
        }
        
        
        int w = 0;      // Naomi's wins while playing war
        {
            int c = 0, ai = n - 1, bi = n - 1;
            while ((ai >= 0) && (bi >= 0))
            {
                if (a[ai] > b[bi])
                {
                    ai--;
                    if (c > 0) c--;
                    else w++;
                }
                else
                {
                    bi--;
                    c++;
                }
            }
        }
        
        fout << "Case #" << (tcase + 1) << ": " << d << " " << w << endl;
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}

