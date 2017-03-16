//
//  main.cpp
//  abcd
//
//  Created by cyanic MayDay on 12-4-14.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <math.h>

int t[101];

int main(int argc, const char * argv[])
{
    ifstream is("/Users/ccyanic/Downloads/B-large.in.txt");
    ofstream os("/Users/ccyanic/Downloads/B-large.out.txt");
    string space;
    
    int n, total, temp, surprising, nosurprising;
    is >> n;
    
    for (int i = 0; i < n; i ++) {
        total = 0;
        nosurprising = 0;
        surprising = 0;
        int N, S, p;
        is >> N >> S >> p;
        if (p == 0) {
            os << "Case #" << i + 1 <<": " << N << endl;
            getline(is, space);
            continue;
        }
        if (p == 1) {
            for (int t = 0; t < N; t ++) {
                is >> temp;
                if (temp > 0) {
                    total ++;
                }
            }
            os << "Case #" << i + 1 <<": " << total << endl;
            continue;
        }
        else {
            for (int t = 0; t < N; t ++) {
                is >> temp;
                if (temp > 3 * p - 3) {
                    nosurprising ++;
                }
                else {
                    if (temp >= 3 * p - 4) {
                        surprising ++;
                    }
                }
            }
            total = nosurprising + min(surprising, S);
            os << "Case #" << i + 1 <<": " << total << endl;
        }
        
    }
    
    return 0;
}

