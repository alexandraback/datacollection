//
//  main.cpp
//  P2
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
using namespace std;

#define MAXN 1001
int T;
int N;

int R[MAXN][2];

int C[MAXN];


int Steps;
bool solve(int completed,int step, int star){
    
    if (completed==N) {
        if (step<Steps || Steps<0) {
            Steps=step;
        }
        return true;
    }

    for (int i=1; i<=N; i++) {
        if (C[i]==0 && star>=R[i][1]) {
            C[i]=2;
            if(solve(completed+1, step+1, star+2))
                return true;
            C[i]=0;
        }else if(C[i]==1 && star>=R[i][1]){
            C[i]=2;
            if(solve(completed+1, step+1, star+1))
                return true;
            C[i]=1;
        }
    }
    
    bool solved=false;
    for (int i=1; i<=N; i++) {
        if (C[i]==0 && star>=R[i][0]) {
            C[i]=1;
            if(solve(completed, step+1, star+1))
                solved=true;
            C[i]=0;
        }

    }
    return solved;
    
}


int main (int argc, const char * argv[])
{
    
    ofstream fout("fout.txt");
    ifstream fin("B-small-attempt6.in");
    
    fin>>T;
    
    
    for (int caseIndex=1; caseIndex<=T; caseIndex++) {
        
        fin>>N;
        
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        Steps=-1;
        
        for (int i=1; i<=N; i++) {
            fin>>R[i][0]>>R[i][1];
        }
        
        if (solve(0, 0, 0)) {
            fout<<"Case #"<<caseIndex<<": "<<Steps;
            cout<<"Case #"<<caseIndex<<": "<<Steps;
        }else{
            fout<<"Case #"<<caseIndex<<": "<<"Too Bad";
            cout<<"Case #"<<caseIndex<<": "<<"Too Bad";
        }
        if (caseIndex<T) {
            fout<<endl;
            cout<<endl;
        }
    }
    
    
    
    return 0;
}
