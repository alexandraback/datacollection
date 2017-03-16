//
//  main.cpp
//  3
//
//  Created by Wanjia He on 4/9/16.
//  Copyright © 2016 Wanjia He. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void print(int num, int digits, ofstream &fout){
    int i;
    for (i = digits; i >= 0; i--){
        if ((num & (1 << i)) != 0){
            fout << '1';
        }else{
            fout << '0';
        }
    }
}

void base_print(int num, int base, ofstream &fout){
    long ans = 0, base_now = 1;
    while (num > 0){
        ans += base_now * (num % 2);
        base_now *= base;
        num = num / 2;
    }
    fout << ' ' <<  ans;
}

int main(int argc, const char * argv[]) {
    ifstream fin;
    ofstream fout;
    fin.open("3.in");
    fout.open("3.out");
    int n, k, i, j, s;
    fin >> n;
    fin >> n >> k;
    s = (1 << (n / 2 - 1)) + 1;
    fout << "Case #1: " << endl;
    for (j = 0; j < k; j ++){
        print(s, n / 2 - 1, fout);
        print(s, n / 2 - 1, fout);
        for (i = 2; i <= 10; i++){
            base_print(s, i, fout);
        }
        fout << endl;
        s = s + 2;
    }
    cout << "done" << endl;
    fin.close();
    fout.close();
}
