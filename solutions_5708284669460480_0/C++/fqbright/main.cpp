//
//  main.cpp
//  codejam
//
//  Created by fq_bright on 10/4/15.
//  Copyright (c) 2015 fq_bright. All rights reserved.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;


int getMaxSuf(string s) {
    
    for (int i = 1; i < s.length(); ++i) {
        int len = 0;
        for (len = 0; i+len < s.length(); ++len) {
            if (s[len] != s[i+len])
                break;
        }
        if (i+len == s.length())
            return i;
    }
    return s.length();
}

int main() {
    string path = "/Users/fq_bright/Desktop/B-small-attempt1.in";
    string out_path = "/Users/fq_bright/Desktop/ret.txt";
    ifstream ifs;
    ofstream ofs;
    
    ofs.open(out_path.c_str());
    ifs.open(path.c_str());
    int T;
    string tt = "Case #";
    ifs >> T;
    int time = 1;
    ofs.precision(8);
    while (time <= T) {
        int N;
        double ret = -1;
        
        int K,L,S;
        ifs>>K>>L>>S;
        int alp[100];
        memset(alp, 0, 400);
        for (int i = 0; i < K; ++i) {
            char tmp;
            ifs >> tmp;
            alp[tmp-'A']++;
        }
        string target;
        ifs >> target;
        double prob = 1;
        for (int i = 0; i < L; ++i) {
            if (alp[target[i]-'A'] == 0 || S < L) {
                ret = 0;
                break;
            }
            prob *= (double)alp[target[i]-'A']/K;
        }
        
        if (ret != 0) {
        double worseCase, avgCase;
        avgCase = (S-L+1)*prob;
            cout << avgCase << endl;
        int maxSuf = getMaxSuf(target);
        worseCase = (S-L)/maxSuf + 1;
            cout << worseCase << endl;
            ret = worseCase - avgCase;
        }
        ofs << tt;
        ofs << time++;
        ofs << ": ";
        ofs << ret << endl;
    }
    ifs.close();
    ofs.close();
    system("pause");
}










