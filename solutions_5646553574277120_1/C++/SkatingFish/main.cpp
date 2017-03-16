//
//  main.cpp
//  2015C_C
//
//  Created by Liubing Yu on 5/10/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <math.h>
typedef long long ll;
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);
long long coins[102];
long long value[102];


long long go(long long n, long long m, long long va){
    long long i;
    for(i =0; i<m; i++){
        ifs >>coins[i];
    }
    coins[i] = 100000;
    long long pos = 0;
    long long j = 0;
    long long res = 0;
    for( long long i = 1;i <= va; )
    {
        while(i >= coins[j])
        {
            pos = coins[j] *n +pos;
            if(pos > 1e9) return res;
            j++;
        }
        if( i > pos && i < coins[j])
        // inset one coin
        {
            pos = i *n + pos;
            if(pos > 1e9) return res;
            cout << i <<" inserting"<<endl;
            res++;
        }
        if( i == pos) i++;
        else i = pos;
    }
    return res;
    
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


