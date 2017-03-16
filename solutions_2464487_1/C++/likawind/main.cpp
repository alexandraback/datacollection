//
//  main.cpp
//  a
//
//  Created by zhou on 13-4-26.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[])
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int tk;
    in>>tk;
    for(int ts=0;ts<tk;ts++){
        long long t,ra;
        in>>ra>>t;
        long long l=0;
        long long r=2e9;
        long long m;
        ra=ra*2+1;
        long long re;
        while (l+1<r) {
            m=(l+r)/2;
            if(((double)ra+ra+4*m-4)*m/2.0<=t){
                re=m;
                l=m;
            }
            else
                r=m;
        }
        
        out<<"Case #"<<ts+1<<": "<<re<<endl;
    }

}

