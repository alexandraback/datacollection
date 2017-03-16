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
using namespace std;

int main (int argc, const char * argv[])
{
    ifstream fin("C-small-attempt0.in", ifstream::in);
    ofstream fout("C-small-attempt0.out", ofstream::out);

    
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
        int temp,temp1,temp2, y = 0;
        for(int j = A; j <= B; j++){
            bool* checked = new bool[B+1];
            for(int x=0;x<B+1;x++) checked[x] = false;
            for(int k = 1; k < digit; k++){
                temp1 = (int)j/pow(10.0, k);
                temp2 = j%(int)pow(10.0, k) * pow(10.0, digit - k);
                temp = temp1 + temp2;
                if(temp > j && temp <= B){
                    if(!checked[temp]){
                        y++;
                        checked[temp]=true;
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

