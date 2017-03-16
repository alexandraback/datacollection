//
//  c.cpp
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

    int R, C, M;
    inFile >> R >> C >> M;

    int S = R*C-M;

    char grid[50][50];
    
    for (int r=0; r<R; r++)
        for (int c=0; c<C; c++)
            grid[r][c]='*';
    
    if (R==1)
    {
        for (int c=1; c<S; c++)
            grid[0][c]='.';
        goto good;
    }
    if (C==1)
    {
        for (int r=1; r<S; r++)
            grid[r][0]='.';
        goto good;
    }
    if (S==1)
    {
        goto good;
    }
    
    for (int w=2; w<=C; w++)
    {
        for (int h=2; h<=R; h++)
        {
            if (S <= w*h && 2*(w+h-2) <= S)
            {
                int x = S-2*(w+h-2);
                
                for (int r=0; r<h; r++)
                {
                    for (int c=0; c<w; c++)
                    {
                        if (r<2 || c<2)
                        {
                            grid[r][c]='.';
                        }
                        else if (x>0)
                        {
                            grid[r][c]='.';
                            x--;
                        }
                    }
                }
                goto good;
            }
        }
    }

    std::cout << "Impossible\n";
    return;
    
    good:

    grid[0][0]='c';
    for (int r=0; r<R; r++)
    {
        for (int c=0; c<C; c++)
        {
            std::cout << grid[r][c];
        }
        std::cout << "\n";
    }

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
        std::cout << "Case #" << caseIndex << ":\n";
        processCase();
    }
    
    return 0;
}
