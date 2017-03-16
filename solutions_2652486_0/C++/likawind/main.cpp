//
//  main.cpp
//  C
//
//  Created by zhou on 13-4-26.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;
int r,n,m,k;
vector<int> f;
vector<vector<int> >all;
int s[100];
int check[1000][100]={};
void compute(int k){
    check[k][1]=1;
    for (int i=0; i<n; i++) {
        for (int j=100; j>0; j--) {
            if (check[k][j]) {
                check[k][j*all[k][i]]=1;
            }
        }
    }
}
void solve(int t){
    if (t==n) {
        all.push_back(f);
        int s=all.size()-1;
        compute(s);
        return;
    }
    for (int i=2; i<=m; i++) {
        f[t]=i;
        solve(t+1);
        
    }
}    ifstream in("in.txt");
    ofstream out("out.txt");

int isGood(int f){

    for (int i=0; i<k; i++) {
        if (!check[f][s[i]]) {
            return 0;
        }
    }
    out<<all[f][0]<<all[f][1]<<all[f][2]<<endl;

    return 1;
    
}
int main(int argc, const char * argv[])
{
    /*R = 100.
    N = 3.
    M = 5.
    K = 7.*/
    
    int tk;
    in>>tk;
    in>>r>>n>>m>>k;
    for (int i=0; i<n; i++) {
        f.push_back(0);
    }
    out<<"Case #"<<1<<": "<<endl;
    solve(0);
    for(int ts=0;ts<r;ts++){
        for (int i=0; i<k; i++) {
            in>>s[i];
        }
        for (int i=0; i<all.size();i++) {
            if(isGood(i))break;
        }
    }
    
}

