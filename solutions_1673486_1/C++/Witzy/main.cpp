//
//  main.cpp
//  P1
//
//  Created by Witzy Huang on 12-4-28.
//  Copyright (c) 2012年 SinoSoft. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <memory.h>
#include <climits>
#include <string.h>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAXN 100000
int T;
int A,B;

double P[MAXN];
double PR[MAXN];
double pro(){
    double p=1;
    PR[0]=1;
    for (int i=1; i<=A; i++) {
        p*=P[i];
        PR[i]=p;
    }
    return p;
}


double solve(){
    
    //keep typing
    double pr=pro();
    double p1=(B-A+1)*pr+(2*B-A+2)*(1-pr);
    
    // back i
    double p2=2*B+2;
    double pt=0;
    for (int i=0; i<A; i++) {
        pr=PR[i];
        pt=pr*(2*(A-i)+B-A+1)+(1-pr)*(2*(A-i)+2*B-A+2);
        p2=p2>pt?pt:p2;
    }
    
    //give up
    double p3=B+2;
    
    return min(min(p1, p2), p3);
    
    
    
    
    
    
}

int main (int argc, const char * argv[])
{
    
    ofstream fout("fout.txt");
    ifstream fin("A-large.in");

    fin>>T;
    
    for (int caseIndex=1; caseIndex<=T; caseIndex++) {
        fin>>A>>B;
        for (int i=1; i<=A; i++) {
            fin>>P[i];
        }
        fout.setf(ios::fixed);
        fout<<setprecision(6)<<"Case #"<<caseIndex<<": "<<solve()<<endl;
        printf("Case #%d: %.6f\n",caseIndex,solve());

    }

    
    
    return 0;
}
