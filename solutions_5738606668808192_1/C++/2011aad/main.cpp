//
//  main.cpp
//  Codejam2016QRoundA
//
//  Created by 张健 on 16/4/9.
//  Copyright © 2016年 张健. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

long divisor[9];
int pointer = 0;
bool isprime(long n){
    for(long i=2;i*i<=n;i++){
        if(n%i==0){
            divisor[pointer] = i;
            return false;
        }
    }
    return true;
}

long to_n_base(long num, int n){
    long r = 0;
    int fact = 1;
    while(num>0){
        r += (num & 1) * fact;
        fact *= n;
        num = num >> 1;
    }
    pointer = n - 2;
    return r;
}

string to_String(long n){
    string s = "";
    for(int i=0;i<32;i++){
        s = (char)((n & 1) + '0') + s;
        n = n >> 1;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream infile("C-large.in");
    ofstream outfile("C-large.out");

    int T, N, J;
    long s;

    int counter = 0, bits, tmp;
    bool flag;
    infile>>T>>N>>J;
    outfile<<"Case #1: "<<endl;
    for(s=3;s<=4294967295;s+=2){
        flag = true;
        for(int i=2;i<=10;i++){
            if(isprime(to_n_base(s,i))){
                flag = false;
                break;
            }
        }
        if(flag){
            counter++;
            tmp = s;
            bits = 0;
            while(tmp>0){
                bits++;
                tmp = tmp >> 1;
            }

            tmp = 1;
            tmp = tmp << (N-bits);
            tmp++;
            outfile<<to_String(s*tmp);

            for(int i=0;i<9;i++){
                outfile<<' '<<divisor[i];
            }
            outfile<<endl;
        }
        if(counter==J) break;
    }

    infile.close();
    outfile.close();

    return 0;
}
