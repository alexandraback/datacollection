//
//  main.cpp
//  codeJam2013
//
//  Created by Guillaume Derval on 13/04/13.
//  Copyright (c) 2013 Guillaume Derval. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>

struct Chest
{
    int key_needed;
    std::vector<int> keys;
};

struct Status
{
    std::map<int,int> keys_available;
    std::map<int,int> keys_needed_after;
    int here;
};

int main(int argc, const char * argv[])
{
    std::ifstream finput ("/Users/guillaumederval/Dropbox/Q4_INFO_perso/codeJam2013/codeJam2013/A-small.in");
    std::ofstream foutput ("/Users/guillaumederval/Dropbox/Q4_INFO_perso/codeJam2013/codeJam2013/out.out");
    
    //std::istream& input = std::cin;
    //std::ostream& output = std::cout;
    std::istream& input = finput;
    std::ostream& output = foutput;
    
    int maximum = 10000000;
    
    int T;
    input >> T;
    for(int test = 0; test < T; test++)
    {
        int baseSize, nbMotes;
        input >> baseSize >> nbMotes;
        
        std::vector<int> motes(nbMotes);
        for(int i = 0; i < nbMotes; i++)
            input >> motes[i];
        
        std::sort(motes.begin(), motes.end());
        
        int nSize = baseSize;
        int best = -1;
        int added = 0;
        for(int i = 0; i < motes.size() && nSize < 10000000; i++)
        {
            if(nSize <= motes[i])
            {
                int todelete = motes.size()-i;
                if(added+todelete < best || best == -1)
                    best = added+todelete;
                if(nSize == 1) //impossible...
                {
                    added = best+1;
                    break;
                }
                while(nSize <= motes[i])
                {
                    added++;
                    nSize += nSize-1;
                }
            }
            nSize += motes[i];
        }
        if(best == -1 || best > added)
            best = added;
        output << "Case #" << (test+1) << ": " << best;
        output << std::endl;
    }
    
    finput.close();
    foutput.close();
    return 0;
}

