//
//  main.cpp
//  google code jam
//
//  Created by Guillaume Derval on 14/04/12.
//  Copyright (c) 2012 ITSelf.be. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>

/*struct CompareCase : public std::binary_function<Case, Case, bool>
{
    bool operator()(const Case lhs, const Case rhs) const
    {
        return lhs.lastT > rhs.lastT;
    }
};*/

int main (int argc, const char * argv[])
{
    std::ifstream fin ("/Users/guillaumederval/Desktop/in.in", std::ifstream::in);
    std::ofstream fout("/Users/guillaumederval/Desktop/out.out", std::ofstream::out | std::ofstream::trunc);
    
    int tests;
    fin >> tests;
    for(int c = 0; c < tests; c++)
    {
        int N;
        fin >> N;
        std::vector< std::vector<int> > links(N);
        for(int i = 0; i < N; i++)
        {
            int M;
            fin >> M;
            links[i].resize(M);
            for(int j = 0; j < M; j++)
            {
                fin >> links[i][j];
                links[i][j]--; //1->N to 0->N-1
            }
        }
        
        bool found = false;
        for(int i = 0; i < N && !found; i++)
        {
            std::vector< bool > linksVerified(N, false);
            std::stack<int> totest;
            totest.push(i);
            while(!totest.empty())
            {
                int t = totest.top();
                totest.pop();
                if(linksVerified[t])
                {
                    found = true;
                    break;
                }
                else
                {
                    linksVerified[t] = true;
                    for(int j = 0; j < links[t].size(); j++)
                        totest.push(links[t][j]);
                }
            }
        }
        if(found)
            fout << "Case #" << (c+1) << ": " << "Yes" << std::endl;
        else
            fout << "Case #" << (c+1) << ": " << "No" << std::endl;
    }
}