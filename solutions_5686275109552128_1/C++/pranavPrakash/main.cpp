//
//  main.cpp
//  Codejam B
//
//  Created by Pranav Prakash on 4/11/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int numTestCases;
    fin >> numTestCases;
    
    for (int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int numDiners;
        fin >> numDiners;
        
        int minMinutesNeeded = 0;
        
        vector<int> plates(numDiners);
        for (int diner = 0; diner < numDiners; diner++)
        {
            fin >> plates[diner];
            minMinutesNeeded = max(minMinutesNeeded, plates[diner]);
        }
        
        
        for (int minuteBlock = 2; minuteBlock < minMinutesNeeded; minuteBlock++)
        {
            int time = 0;
            for (int numPancakes : plates)
                time += (numPancakes - 1)/minuteBlock;
            minMinutesNeeded = min(minMinutesNeeded, time + minuteBlock);
        }
        
        fout << "Case #" << testCase << ": " << minMinutesNeeded << '\n';
    }
    
    return 0;
}

