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

int compare (const void *elem1, const void *elem2){
    return (int)(*(long*)elem1 - *(long*)elem2);
}

int stepsLeft(long *motes, int numMotes, int i, int currentTotal, long currentSize)
{
    if(i>=numMotes)
        return currentTotal;
    
    if(currentTotal>=numMotes)
        return numMotes;
    
    if(currentSize > motes[i])
        return min(currentTotal+numMotes-i, stepsLeft(motes, numMotes, i+1, currentTotal, currentSize+motes[i]));
    
    else
        return min(currentTotal+numMotes-i, stepsLeft(motes, numMotes, i, currentTotal+1, currentSize+(currentSize-1)));
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
        long moteSize;
        int numMotes;
        
        myfile >> moteSize;
        myfile >> numMotes;
        
        long *motes = new long[numMotes];
        
        for(int j=0; j<numMotes; j++)
        {
            myfile >> motes[j];
        }
        
        qsort((void *)motes, (size_t)numMotes, (size_t)sizeof(long), compare);
        
        cout << "Case #" << i+1 << ": " << stepsLeft(motes, numMotes, 0, 0, moteSize) << endl;
        
        delete [] motes;
    }
    
    myfile.close();
    return 0;
}

