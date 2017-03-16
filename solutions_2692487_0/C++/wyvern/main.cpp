//
//  main.cpp
//  ProblemA
//
//  Created by Brownlee on 13-05-04.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>


using namespace std;

ifstream fin("A-small-attempt1.in");
ofstream fout("out.txt");

int main (int argc, const char * argv[])
{
    int motes[100];
    long long moteSize;
    int nmotes;
    int ncases;
    int nmoves;
    
    int costs[100];
    
    fin>>ncases;
    
    for( int test = 1; test <= ncases; test++){
        fin>>moteSize>>nmotes;
        for( int i = 0; i < 100; i++){
            costs[i] = 99999999;
        }

        nmoves = 0;
        for( int i = 0; i < nmotes; i++){
            fin>>motes[i];
        }
        sort(motes, motes + nmotes);
        
        for( int i = 0; i < nmotes; i++){
            if( motes[i] < moteSize){
                moteSize += motes[i];
            }else{
                if( moteSize == 1){
                    break;
                }
                while (moteSize <= motes[i]) {
                    moteSize += moteSize - 1;
                    nmoves++;
                }
                moteSize+= motes[i];
            }
            costs[i] = nmoves;
        }
        
        int minMoves = nmotes;
        for( int i = 1; i <= nmotes; i++){
            minMoves = costs[i - 1] + nmotes - i < minMoves ? costs[i - 1] + nmotes - i : minMoves; 
        }
        
        fout<<"Case #"<<test<<": "<<minMoves<<"\n";
    }
}

