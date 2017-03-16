//
//  main.cpp
//  CodeJamQ3
//
//  Created by Ha Young Park on 4/13/12.
//  Copyright (c) 2012 UCLA. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
using namespace std;

int main (int argc, const char * argv[])
{
    ifstream fin("C-large.in", ifstream::in);
    ofstream fout("C-large.out", ofstream::out);
    
    int N,A,B;
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> A >> B;
        int d = B;
        int digit = 0;
        while(d != 0){
            d /= 10;
            digit++;
        }
        
        int temp, y = 0;
        for(int j = A; j <= B; j++){
            set<int> found;
            for(int k = 1; k < digit; k++){
                temp = (int)j/pow(10.0, k) + j%(int)pow(10.0, k) * pow(10.0, digit - k);
                if(temp > j && temp <= B){
                    if(found.count(temp) == 0){    //not found
                        y++;
                        found.insert(temp);
                    }
                }
            }
        }

        fout << "Case #" << i + 1 << ": " << y << endl;
    }
    fin.close();
    fout.close();
    return 0;
}

