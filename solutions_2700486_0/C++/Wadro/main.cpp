//
//  main.cpp
//  CodeJam
//
//  Created by Wade Norris on 4/26/13.
//  Copyright (c) 2013 norris. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

long getShellNum(long x, long y)
{
    return (x+y)/2;
}

long getNumOuterDiamonds(long n, long s)
{
    long numInteriorDiamonds = ((s-1)*2 + 1)*(((s-1)*2 + 1)+1)/2;
    
    if(numInteriorDiamonds > n)
        return 0;
    
    return n-numInteriorDiamonds;
}

int main(int argc, const char * argv[])
{
    if(argc < 2)
        return -1;
    
    ifstream myfile;
    myfile.open(argv[1]);
    
    int numTestCases;
    myfile >> numTestCases;
    
    for(int i=0; i<numTestCases; i++)
    {
        long numDiamonds;
        long xCoord;
        long yCoord;
        
        myfile >> numDiamonds;
        myfile >> xCoord;
        myfile >> yCoord;
        
        long shellNum = getShellNum(xCoord, yCoord);
        
        long outterDiamonds = getNumOuterDiamonds(numDiamonds, shellNum);
        long outterOutterDiamonds = getNumOuterDiamonds(numDiamonds, shellNum+1);
        if(outterDiamonds == 0)
        {
            cout << "Case #" << i+1 << ": " << "0.0" << endl;
        }
        else if(outterOutterDiamonds > 0)
        {
            cout << "Case #" << i+1 << ": " << "1.0" << endl;
        }
        else if(yCoord > outterDiamonds)
        {
            cout << "Case #" << i+1 << ": " << "0.0" << endl;
        }
        else
        {
            cout << "Case #" << i+1 << ": " << (double)yCoord/(double)outterDiamonds << endl;
        }

    }
    
    myfile.close();
    return 0;
}

