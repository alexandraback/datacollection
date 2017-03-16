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
#include <set>
#include <cmath>
using namespace std;



int main(int argc, const char * argv[]) {
    ifstream aaa("/Users/ahmagdy/Downloads/C-small-attempt2.in");
    int nn;
    aaa >> nn;
    
    for(int ii = 1 ; ii <= nn; ii++){
        int nnn ;
        aaa >> nnn;
        
        vector<string> firsts;
        vector<string> seconds;
        for(int i = 0 ; i < nnn ; i ++){
            string s1, s2;
            aaa >> s1 >> s2;
            firsts.push_back(s1);
            seconds.push_back(s2);
        }
        int maxF = 0;
        for(int i = 0 ; i < 1<<nnn; i ++){
            set<string> orgF;
            set<string> orgS;
            set<string> fakeF;
            set<string> fakeS;
            for(int j = 1, k = 0; k < nnn ; j*=2, k ++){
                int isFake = i & j;
                if(isFake == 0){
                    orgF.insert(firsts[k]);
                    orgS.insert(seconds[k]);
                }
                else{
                    fakeF.insert(firsts[k]);
                    fakeS.insert(seconds[k]);
                }
            }
            bool bre= false;
            for(string possibleFake:fakeF){
                if(orgF.find(possibleFake) == orgF.end()){
                    bre = true;
                    break;
                }
            }
            
            for(string possibleFake:fakeS){
                if(orgS.find(possibleFake) == orgS.end()){
                    bre = true;
                    break;
                }
            }
            if(bre)
                continue;
            maxF = max(maxF, (int) fakeS.size());
        }
        
        
        cout << "Case #" << ii<< ": " << maxF << endl;
        
    }
    return 0;
}


