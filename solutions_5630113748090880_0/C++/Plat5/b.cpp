//
//  b.cpp
//  CodeJam16
//
//  Created by Ahmed Mohammed on 4/16/16.
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

static int sortIdx;
int cmp(vector<int> &l, vector<int> &r) { return l[sortIdx] < r[sortIdx]; }

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
        
        int N; fin >> N;
        vector<vector<int>> G;
        for (int i = 0; i < (2 * N - 1); i++)
        {
            vector<int> g;
            for (int j = 0; j < N; j++)
            {
                int tmp; fin >> tmp;
                g.push_back(tmp);
            }
            G.push_back(g);
        }
        
        vector<pair<vector<int>, vector<int>>> pairs;
        int missingIdx = -1;
        
        for (int i = 0; G.size(); i++)
        {
            sortIdx = i;
            sort(G.begin(), G.end(), cmp);
            
            if ((G.size() == 1) || (G[0][i] != G[1][i]))
            {
                assert(missingIdx == -1);
                missingIdx = i;
                vector<int> v;
                pairs.push_back(pair<vector<int>, vector<int>>(G[0], v));
                G.erase(G.begin());
            }
            else
            {
                pairs.push_back(pair<vector<int>, vector<int>>(G[0], G[1]));
                G.erase(G.begin());
                G.erase(G.begin());
            }
        }

        vector<int> ans;
        for (int i = 0; i < pairs.size(); i++)
        {
            if (i == missingIdx) ans.push_back(pairs[i].first[i]);
            else
            {
                if (pairs[i].first[missingIdx] == pairs[missingIdx].first[i]) ans.push_back(pairs[i].second[missingIdx]);
                else ans.push_back(pairs[i].first[missingIdx]);
            }
        }
        
        for (int i = 0; i < ans.size(); i++) fout << ' ' << ans[i];
        fout << endl;
    }
    
    
    fin.close();
    fout.close();
    
    return 0;
}