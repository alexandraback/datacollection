//
//  main.cpp
//  20151B_A
//
//  Created by Liubing Yu on 5/2/15.
//  Copyright (c) 2015 Liubing Yu. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
ifstream ifs ("/Users/yuliubing/Desktop/input.txt", std::ifstream::in);
ofstream ofs ("/Users/yuliubing/Desktop/output.txt", std::ofstream::out);
int* p= new int[1000002];
int needF;

int reverse_N(int n){
    int doneN = 0;
    while(n>0){
        doneN = doneN *10 +n%10;
        n=n/10;
    }
    return (doneN);
}


void go(int n){
    for(int i =1; i<=1e6;i++ )
        p[i] = 10e6;
    p[1]=1;
    for(int i =1; i<=1e6;i++ ){
        p[i+1] = min(p[i+1],p[i]+1);
        int m =reverse_N(i);
        p[m] =min(p[m],p[i]+1);
    }
}


int main(int argc, const char * argv[]) {
    int n,l, k;
    go(1);
    ifs >> n;
    cout << n <<" a"<<endl;
    for (int i = 0; i < n; i++){
        ifs >> l;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        int total = p[l];
        cout << "Ans" <<total;
        ofs << total;
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


