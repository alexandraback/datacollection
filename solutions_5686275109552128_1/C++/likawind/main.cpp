//
//  main.cpp
//  a
//
//  Created by Zhou Sun on 15/4/11.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int ts,k;
    ifstream in("b.txt");
    ofstream out("b_out.txt");
    in>>ts;
    int a[10000];
    for (int tt=1; tt<=ts; tt++) {
        int d;
        in>>d;
        for (int i=0;i<d; i++) {
            in>>a[i];
        }
        int re=10000;
        for (int i=1; i<1001; i++) {
            int s=0;
            for (int j=0; j<d; j++) {
                s+=(a[j]-1)/i;
            }
            re=min(re,s+i);
        }
        out<<"Case #"<<tt<<": "<<re<<endl;
    }
    return 0;
}
