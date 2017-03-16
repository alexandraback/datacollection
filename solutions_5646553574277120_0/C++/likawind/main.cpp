//
//  main.cpp
//  C
//
//  Created by Zhou Sun on 15/5/10.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int a[100];
int f[100];
int main(int argc, const char * argv[]) {
    int ts,c,d,v;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in>>ts;
    for (int tt=1; tt<=ts; tt++) {
        in>>c>>d>>v;
        memset(f, 0, sizeof(f));
        f[0]=1;
        for (int i=0; i<d; i++) {
            in>>a[i];
            for (int j=v; j>=a[i]; j--) {
                if(f[j-a[i]])f[j]=1;
            }
        }
        int s=0;
        for (int i=1; i<=v; i++) {
            if (f[i]) {
                continue;
            }
            s++;
            for (int j=v; j>=i; j--) {
                if(f[j-i])f[j]=1;
            }
        }
        out<<"Case #"<<tt<<": "<<s<<endl;
    }
    return 0;
}
