//
//  main.cpp
//  PalindromeSq
//
//  Created by Stephen Zhu on 4/13/13.
//  Copyright 2013 University of Michigan. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


int main ()
{
    long long motes[101];
    ifstream in("A-large.in");
    ofstream out("output.txt");
    int T;
    int c = 1;
    
    in >> T;
    
    while ( c <= T ){
        long long a;
        int numMotes;
        in >> a >> numMotes;
        for (int i = 0; i < numMotes; i++){
            in >> motes[i];
        }
        sort(motes, motes+numMotes);
        long long cost[101];
        
        if (a == 1){
            out << "Case #" << c << ": " << numMotes << endl;
        }
        else {
            long long curSize = a;
            long long totalCost = 0;
        
            for (int i = 0; i < numMotes; i++){
                long long curCost = 0;
                while (curSize <= motes[i] ){
                    curSize += curSize - 1;
                    curCost++;
                }
                curSize += motes[i];
                cost[i] = curCost;
                totalCost += curCost;
            }
            
            long long minCost = totalCost;
            
            for ( int i = numMotes - 1; i >= 0; i--){
                totalCost = totalCost - cost[i] + 1;
                minCost = min(minCost, totalCost);
            }
            
           out << "Case #" << c << ": " << minCost << endl;
        }
        c++;
        
    }
    
    
    return 0;
}

