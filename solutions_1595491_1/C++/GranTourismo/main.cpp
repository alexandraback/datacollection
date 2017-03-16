//
//  main.cpp
//  CodeJamQ2
//
//  Created by Ha Young Park on 4/13/12.
//  Copyright (c) 2012 UCLA. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, const char * argv[])
{
    ifstream fin("B-large.in", ifstream::in);
    ofstream fout("B-large.out", ofstream::out);
    
    int N,T,S,P,testCase;
    fin >> N;
    for(int i = 0; i < N; i++){
        int y = 0;
        fin >> T >> S >> P;
        for(int j = 0; j < T; j++){
            fin >> testCase;
            if(testCase >= P){
                if((testCase - P) >= (P - 1) * 2)
                    y++;
                else if(S > 0 && (testCase - P) >= (P - 2) * 2){
                    y++;
                    S--;
                }
            }
            
        }
        fout << "Case #" << i + 1 << ": " << y << endl;
    }
    fin.close();
    fout.close();
    return 0;
}

