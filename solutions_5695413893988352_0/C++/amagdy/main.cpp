//
//  main.cpp
//  bfs
//
//  Created by Ahmed Magdy Hamed Mohamed on 4/21/16.
//  Copyright © 2016 Ahmed Magdy Hamed Mohamed. All rights reserved.
//

#include <iostream>
#include <algorithm>    // std::sort
#include <vector>
#include <fstream>
using namespace std;

bool isPossible(int x, string s){
    string newS = to_string(x);
    if (newS.length() < s.length()){
        newS = "0" + newS;
    }
    if (newS.length() < s.length()){
        newS = "0" + newS;
    }
    if (newS.length() < s.length()){
        newS = "0" + newS;
    }
    
    for(int i = 0 ; i < s.length() ; i ++){
        if(s[i] == '?')
            continue;
        if(s[i] != newS[i])
            return false;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    ifstream aaa("/Users/ahmagdy/Downloads/B-small-attempt2.in");
    int nn;
    aaa >> nn;
    
    for(int ii = 1 ; ii <= nn; ii++){
        string s1, s2;
        aaa >> s1 >> s2;
        int max = -1;
        if(s1.length() == 1)
            max = 10;
        else if (s1.length() == 2)
            max = 100;
        else
            max = 1000;
        
        int best = 1000000000;
        int bestJ = 0;
        int bestC = 0;
        
        for(int i = 0 ; i < max ; i ++){
            if( !isPossible(i, s1))
                continue;
            
            for(int j = 0 ; j < max ; j ++){
                if(isPossible(j, s2)){
                    
                    if(best > abs(i-j)){
                        best = abs(i-j);
                        bestC = i;
                        bestJ = j;
                    }
                    if(best == abs(i-j)){
                        if(i < bestC){
                            best = abs(i-j);
                            bestC = i;
                            bestJ = j;
                        } else if (j < bestJ){
                            best = abs(i-j);
                            bestC = i;
                            bestJ = j;
                        }
                    }
                }
            }
        }
        string newC = to_string(bestC);
        string newJ = to_string(bestJ);
        
        if (newC.length() < s1.length()){
            newC = "0" + newC;
        }
        if (newC.length() < s1.length()){
            newC = "0" + newC;
        }
        if (newC.length() < s1.length()){
            newC = "0" + newC;
        }
        
        
        if (newJ.length() < s1.length()){
            newJ = "0" + newJ;
        }
        if (newJ.length() < s1.length()){
            newJ = "0" + newJ;
        }
        if (newJ.length() < s1.length()){
            newJ = "0" + newJ;
        }
        
        cout << "Case #" << ii<< ": " << newC << " " << newJ << endl;
        
    }
    return 0;
}


