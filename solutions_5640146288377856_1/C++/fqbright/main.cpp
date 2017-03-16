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



int main() {
    string path = "/Users/fq_bright/Desktop/A-large.in";
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
        int ret;
        
        int r,c,w;
        ifs>>r>>c>>w;
        ret = r*c/w + w;
        if (r*c%w == 0) --ret;
        
        
        ofs << tt;
        ofs << time++;
        ofs << ": ";
        ofs << ret << endl;
    }
    ifs.close();
    ofs.close();
    system("pause");
}










