//
//  main.cpp
//  b
//
//  Created by zhou on 13-4-26.
//  Copyright (c) 2013年 zhou. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
using namespace std;
vector<int>v;
vector<int>f;
vector<int>have;
vector<int>need;

int e,r,n,tem,k;

int mx(int l,int r){
    int mx=l;
    for(int i=l;i<r;i++)
        if(v[i]>v[mx])mx=i;
    return mx;
}
void solve(int left,int right){
    if (left==right) {
        return;
    }
    int m=mx(left,right);
    f[m]=have[left]+(m-left)*r;
    if(f[m]>e)f[m]=e;
    if(need[right]-r*(right-m)>0)
        f[m]-=need[right]-r*(right-m);
    have[m+1]=r;
    need[m]=f[m];
    if(need[right]-r*(right-m)>0){
        need[m]+=need[right]-r*(right-m);
        have[m+1]+=need[right]-r*(right-m);
    }

    solve(left, m);
    solve(m+1, right);
    
}
int main(int argc, const char * argv[])
{
    
    int tk;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in>>tk;
    for(int ts=0;ts<tk;ts++){
        in>>e>>r>>n;
        v.clear();
        f.clear();
        have.clear();
        need.clear();
        k=(e+r-1)/r;
        for (int i=0; i<n; i++) {
            in>>tem;
            v.push_back(tem);
            f.push_back(0);
            have.push_back(0);
            need.push_back(0);
        }
        need.push_back(0);
        have[0]=e;
        solve(0,n);
        int sum=0;
        for (int i=0; i<n; i++) {
            sum+=v[i]*f[i];
        }
        out<<"Case #"<<ts+1<<": "<<sum<<endl;
    }
    
}



