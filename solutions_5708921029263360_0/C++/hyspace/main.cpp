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
#include <map>
#include <sstream>

using namespace std;

void check(map<pair<int, int>, int>&mjp,
           map<pair<int, int>, int>&mjs,
           map<pair<int, int>, int>&mps,
           int j, int p, int s, int K,
           vector<string>& res){
    pair<int, int> jp = pair<int, int>(j, p);
    pair<int, int> js = pair<int, int>(j, s);
    pair<int, int> ps = pair<int, int>(p, s);
    bool add = true;
    if(mjp.find(jp)==mjp.end()){
        mjp.insert(pair<pair<int, int>, int>(jp, 1));
    }else{
        if(mjp[jp] > K){
            add = false;
        }else{
        }
    }
    if(mjs.find(js)==mjs.end()){
        mjs.insert(pair<pair<int, int>, int>(js, 1));
    }else{
        if(mjs[js] > K){
            add = false;
        }else{
        }
    }
    if(mps.find(ps)==mps.end()){
        mps.insert(pair<pair<int, int>, int>(ps, 1));
    }else{
        if(mps[ps] > K){
            add = false;
        }else{
        }
    }
    if(add){
        mps[ps]++;
        mjs[js]++;
        mjp[jp]++;
        res.push_back(to_string(j+1) + " " + to_string(p+1) + " " + to_string(s+1));
    }
}

int main(int argc, const char * argv[]) {
    std::ifstream infile("C-small-attempt0.in");
    std::ofstream outfile("C-small-attempt0.out");
    std::string line;
    std::getline(infile, line);
    int total = atoi(line.c_str());

    
    for (int i = 0; i < total; ++i){
        
        map<pair<int, int>, int>mjp;
        map<pair<int, int>, int>mjs;
        map<pair<int, int>, int>mps;
        
        vector<string> res;
        
        std::string singleLine;
        std::getline(infile, singleLine);
        vector<int> singleLineInt;
        string buf;
        stringstream ss(singleLine);
                    
        while (ss >> buf)
            singleLineInt.push_back(atoi(buf.c_str()));
        
        int J = singleLineInt[0];
        int P = singleLineInt[1];
        int S = singleLineInt[2];
        int K = singleLineInt[3];
        
        for(int j = 0; j < J;++j){
            for(int p = 0; p < P;++p){
                for(int s = 0; s < S;++s){
                    check(mjp, mjs, mps, j, p, s, K, res);
                }
            }
        }
    
        outfile << "Case #" << i+1 << ": " << res.size() << endl;
        for(string s: res){
            outfile << s << endl;
        }
    }
}
