//
//  main.cpp
//  Codejam A
//
//  Created by Pranav Prakash on 4/11/15.
//  Copyright (c) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    int numTestCases;
    cin >> numTestCases;
    
    for (int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int maxShyness;
        cin >> maxShyness;
        
        string shynessLevels;
        cin >> shynessLevels;
        
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
        
        cout << "Case #" << testCase << ": " << numPeopleToAdd << '\n';
    }
    
    
    return 0;
}

