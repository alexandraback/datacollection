//
//  main.cpp
//  Codejam D
//
//  Created by Pranav Prakash on 4/11/15.
//  Copyright (gridC) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int numTestCases;
    fin >> numTestCases;

    for (int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int xOminoe, gridR, gridC;
        fin >> xOminoe >> gridR >> gridC;
        
        bool possible = true;

        if (xOminoe >= 7)
        {
            possible = false;
        }
        else if (xOminoe > gridR and xOminoe > gridC)
        {
            possible = false;
        }
        else if (gridR * gridC % xOminoe != 0)
        {
            possible = false;
        }
        else if ((xOminoe + 1) / 2 > min(gridR, gridC))
        {
            possible = false;
        }
        else if (xOminoe == 1 or xOminoe == 2 or xOminoe == 3)
        {
            possible = true;
        }
        else if (xOminoe == 4)
        {
            possible = min(gridR, gridC) > 2;
        }
        else if (xOminoe == 5)
        {
            possible = !(min(gridR, gridC) == 3 and max(gridR, gridC) == 5);
        }
        else if (xOminoe == 6)
        {
            possible = min(gridR, gridC) > 3;
        }
        
        fout << "Case #" << testCase << ": " << (possible ? "GABRIEL" : "RICHARD") << '\n';
        
    }

    return 0;
}
