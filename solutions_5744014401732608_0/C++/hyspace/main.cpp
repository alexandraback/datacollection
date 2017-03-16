//
//  main.cpp
//  c
//
//  Created by hyspace on 4/8/16.
//  Copyright © 2016 hyspace. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int check(long long B, long long M){
    long long m2 = (0x1 << (B-2));
    if(M > m2){
        return 0;
    }else if(M == m2){
        return 2;
    }else{
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    std::ifstream infile("B-small-attempt1.in");
    std::ofstream outfile("B-small-attempt1.out");
    std::string line;
    std::getline(infile, line);
    int total = atoi(line.c_str());

    
    for (int i = 0; i < total; ++i){
        
        std::string singleLine;
        std::getline(infile, singleLine);
        vector<long long> singleLineInt;
        string buf;
        stringstream ss(singleLine);
                    
        while (ss >> buf)
            singleLineInt.push_back(atoll(buf.c_str()));
        
        int B = singleLineInt[0];
        int M = singleLineInt[1];

        int ans = check(B, M);
        vector<vector<char>> mm;
        if(ans){
            mm.resize(B, vector<char>(B, 0));
            for(long long i = 0; i< B - 1; ++i){
                for(long long j = i + 1; j< B - 1; ++j){
                    mm[i][j] = 1;
                }
            }
            if(ans == 2){
                for(int i = 0; i < B - 1; ++i){
                    mm[i][B - 1] = 1;
                }
            }else{
                for(int i = 0; i < B; ++i){
                    long long s = 0x1 << i;
                    if(M & s){
                        mm[i + 1][B - 1] = 1;
                    }
                }
            }
        }
        
        
        if(!ans){
            outfile << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        }else{
            outfile << "Case #" << i+1 << ": " << "POSSIBLE" << endl;
            for(int i = 0; i < B; ++i){
                for(int j = 0; j < B; ++j){
                    outfile << (int)mm[i][j];
                }
                outfile << endl;
            }
        }
        
    }
}
