//
//  main.cpp
//  Pancakes
//
//  Created by Liubing Yu on 4/11/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);
int p[1000];
void go(int n){
    int l;
    for (int i = 0; i < n; i++){
        ifs >> l;
        p[i] = l;
    }
    cout << n <<" ";
    int totalMinute =0 , minTotalMinute = 10000;
    for( int j = 1; j < 1001; j++)
    {
        totalMinute = 0;
        for (int i = 0; i < n; i++)
        {
            totalMinute += (p[i]-1 )/j;
        }
        minTotalMinute = min( minTotalMinute, totalMinute + j);
    }
    cout << minTotalMinute;
    ofs << minTotalMinute;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n,l;
    
    ifs >> n;
    cout << n <<" a"<<endl;
    for (int i = 0; i < n; i++){
        ifs >> l;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        go(l);
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


