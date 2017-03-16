//
//  main.cpp
//  Consonants
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


inline bool isConsonant(char ch)
{
    return (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u');
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
    
    
    char *name = new char[1000001];
    
    // solve test cases
    uint64_t testcase_count;
    fin >> testcase_count;
    //testcase_count = 1;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        fin >> name;
        int L = (int)strlen(name);
        int N;
        fin >> N;
        
        vector<int> matches;
        
        char *p = name;
        int cc = 0;
        while (*p)
        {
            if (isConsonant(*p))
            {
                cc++;
                if (cc == N)
                {
                    matches.push_back((int)(p - name) - (N - 1));
                    cc--;
                }
            }
            else cc = 0;
            
            p++;
        }
        
        int64_t result = 0;
        for (int j = 0; j < matches.size(); j++)
        {
            int g = (int)matches.size() - j;
            for (int i = 0; i < g; i++)
            {
                int l = matches[i] - (i ? (matches[i-1] + 1) : 0);
                
                int last = i + j;
                int r = ((i == g - 1) ? L : matches[last + 1] + N - 1) - (matches[last] + N);
                
                result += ((uint64_t)l + 1) * (r + 1);
            }
        }
        
        
        
        fout << "Case #" << (tcase + 1) << ": " << result << endl;
    }
    
    
    delete [] name;
    
    fin.close();
    fout.close();
    
    return 0;
}