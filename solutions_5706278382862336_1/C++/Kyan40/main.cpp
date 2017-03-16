//
//  main.cpp
//  11
//
//  Created by Nikifor Zhao on 14-5-11.
//  Copyright (c) 2014年 Han Zhao. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("A-large.in");
ofstream fout("out.txt");

int pt, qt;
long long p, q;
int main(int argc, const char * argv[])
{
    int t;
    char c;
    fin >> t;
    for (int ni = 0; ni < t; ni ++) {
        fin >> p >> c >> q;
        //cout << p << " "<< q;
        long long tq = q;
        while (q % 2 == 0) q /= 2;
        if (p % q != 0) fout << "Case #" << ni + 1<< ": impossible"<<endl;
        else {
            int ans = 0;
            while (1) {
                if (p >= tq) {
                    fout << "Case #" << ni + 1<< ": " << ans << endl;
                    break;
                } else {
                    p *= 2;
                    ans += 1;
                }
            }
        }
    }
    
    return 0;
}

