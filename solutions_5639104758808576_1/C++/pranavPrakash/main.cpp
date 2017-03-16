//
//  main.cpp
//  Codejam A
//
//  Created by Pranav Prakash on 4/11/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int numTestCases;
    fin >> numTestCases;
    
    for (int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int maxShyness;
        fin >> maxShyness;
        
        string shynessLevels;
        fin >> shynessLevels;
        
        int numPeopleToAdd = 0;
        int currentStandingUp = 0;
        
        for (int shyness = 0; shyness < shynessLevels.length(); shyness++)
        {
            if (shyness > currentStandingUp)
            {
                numPeopleToAdd += shyness - currentStandingUp;
                currentStandingUp = shyness;
            }
            currentStandingUp += shynessLevels[shyness] - '0';
        }
        
        fout << "Case #" << testCase << ": " << numPeopleToAdd << '\n';
    }
    
    
    return 0;
}

