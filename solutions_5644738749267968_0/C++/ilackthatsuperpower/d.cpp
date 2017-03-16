//
//  d.cpp
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

// reads double vector from text file
void readVec
(
    std::ifstream & inFile,
    std::vector<double> & v,
    int const N // number of elements
)
{
    v.resize(N);
    for (int i=0; i<N; i++)
        inFile >> v[i];
}


// globals

std::ifstream inFile;

// functions

void setup()
{
}


void processCase()
{

    int N;

    inFile >> N;

    std::vector <double> bn(N), bk(N);

    readVec(inFile,bn,N);
    readVec(inFile,bk,N);

    std::sort(bn.begin(), bn.end());
    std::sort(bk.begin(), bk.end());
    
    // war
    
    int wpK = 0;
    int in = 0;
    int ik = 0;
    while(in<N && ik<N)
    {
        if (bn[in]>bk[ik])
        {
            ik++;
        }
        else
        {
            wpK++;
            in++;
            ik++;
        }
    }
    int wpN = N-wpK;
    
    // deceitful war
    
    int dwpN = 0;
    in=0;
    ik=0;
    
    while (in<N && ik<N)
    {
        if (bk[ik]>bn[in])
        {
            in++;
        }
        else
        {
            dwpN++;
            in++;
            ik++;
        }
    }
    
    
    

    std::cout << dwpN << " " << wpN << "\n";
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
