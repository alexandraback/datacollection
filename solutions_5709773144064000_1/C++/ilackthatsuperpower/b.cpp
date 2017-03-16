//
//  b.cpp
//
//

#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

//#include <boost/multi_array.hpp>


// function prototypes

// utility functions

// globals

std::ifstream inFile;

// functions

void setup()
{
}


void processCase()
{

    double C,X,F;
    const double R=2.0;

    inFile >> C >> F >> X;

    int n=0;
    double bestT=X/R;
    double ft=0.0;
    
    while(1)
    {
        double t;
        ft += C/(R+n*F);
        n++;
        t = ft+X/(R+n*F);
        if (t>bestT)
            break;
        bestT=t;
    }
    

    std::cout << bestT << "\n";
}


// main

int main(int argc, char const * argv[])
{

    int T;
    
    // make sure filename is provided
    if (argc != 2)
    {
        std::cout << "Expected one argument\n";
        std::exit(0);
    }
    
    // open input file
    inFile.open(argv[1]);
    
    inFile >> T;
    
    
    setup();
    
    std::cout << std::setprecision(9);
    
    for (int caseIndex=1; caseIndex<=T; caseIndex++)
    {
        std::cout << "Case #" << caseIndex << ": ";
        processCase();
    }
    
    return 0;
}
