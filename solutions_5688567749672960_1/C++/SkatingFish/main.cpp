//
//  main.cpp
//  2015B_A1
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

long long * q= new long long[17];
long long needF;

long long reverse_N(long long n){
    long long doneN = 0;
    while(n>0){
        doneN = doneN *10 +n%10;
        n=n/10;
    }
    return (doneN);
}

long long length_N(long long n){
    long long doneN = 0;
    while(n>0){
        doneN++;
        n=n/10;
    }
    return (doneN);
}


long long go1(long long n){
    if(n%10 == 0) return go1(n-1) + 1;
    long long len = length_N(n);
    long long res = 0;
    long long num = 1;
    for (long long i =0; i < (len+1)/2; i++)
    {
        num = num *10;
    }
    long long half = num;
    res = n%half;
    n = n/half;
    n = reverse_N(n);
    cout << n << "  "<< half<<endl;
    if(n==1) return res+1;
    res++;
    return res+n;
}
void go2(long long n){
    q[1]=0;
    q[2]=9;
    long long m =99;
    for(long long i =3; i<=16;i++ )
    {
        q[i]=q[i-1]+go1(m);
        m = m*10+9;
    }
}
long long go3(long long n){
    if(n <10) return n;
    if(n%10 == 0) return go3(n-1) + 1;
    long long len =length_N(n);
    return(go1(n)+q[len]);
}

int main(int argc, const char * argv[]) {
    long long n,l, k;
    go2(1);
    ifs >> n;
    cout << n <<" a"<<endl;
    for (long long i = 0; i < n; i++){
        ifs >> l;
        cout << "Case #" << i + 1 << ": ";
        ofs << "Case #" << i + 1 << ": ";
        long long total = go3(l);
        
        cout << "Ans" <<total;
        ofs << total;
        cout << endl;
        ofs << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}


