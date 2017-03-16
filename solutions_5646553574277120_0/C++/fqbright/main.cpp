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
#include <iostream>a
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;



bool solve(vector<int> a, int v, int c) {
    if (v==0) return true;
    if (a.empty()) return false;
    int tmp = a[a.size()-1];
    a.pop_back();
    for (int i = 0; i <= c; ++i) {
        if (v >= i*tmp) {
            if (solve(a,v-i*tmp,c))
                return true;
        }
    }
    return false;
}

int main() {
    string path = "/Users/fq_bright/Desktop/C-small-attempt1.in";
    string out_path = "/Users/fq_bright/Desktop/ret.txt";
    ifstream ifs;
    ofstream ofs;
    
    ofs.open(out_path.c_str());
    ifs.open(path.c_str());
    int T;
    string tt = "Case #";
    ifs >> T;
    int time = 1;
    while (time <= T) {
        int N;
        int ret = 0;
        
        int c,d,v;
        ifs>>c>>d>>v;
        vector<int> a;
        for (int i = 0 ; i < d; ++i) {
            int tmp;
            ifs>>tmp;
            a.push_back(tmp);
        }
        for (int i = 1; i <= v; ++i) {
            if (solve(a, i, c))
                continue;
            ++ret;
            a.push_back(i);
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










