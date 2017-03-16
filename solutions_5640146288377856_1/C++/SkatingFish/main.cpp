//
//  main.cpp
//  2015C_A
//
//  Created by Liubing Yu on 5/10/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
typedef long long ll;
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);
long long needF;

long long go(long long n, ll m, ll k){
    int res;
    int trytimes = m  /k;
    res = n * trytimes;
    if(m == k || m%k ==0) return res+k-1;
    return res+k;
}


int main(int argc, const char * argv[]) {
    long long n,l,j, k;
    ifs >> n;
    cout << n <<" a"<<endl;
    for (long long i = 0; i < n; i++){
        ifs >> l >> j>> k;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        long long total = go(l, j, k);
        cout << "Ans" <<total;
        ofs << total;
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


