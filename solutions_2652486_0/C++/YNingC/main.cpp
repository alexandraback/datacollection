//
//  main.cpp
//  GCJ_R1A_C
//
//  Created by Ningchen Ying on 4/27/13.
//  Copyright (c) 2013 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>

using namespace std;
int T,R,N,M,K;
int S[20];
int A[10];
int m[20];
bool f;
bool check(int h){
    int r=1<<K;
    for(int i=0;i<r;i++){
        int hh=i;
        int cnt=1;
        for(int j=0;j<N;j++){
            if(hh%2==1){
                cnt*=A[j];
            }
            hh/=2;
        }
        if(cnt==h) return true;
    }
    return false;
}
void dfs(int h){
    if(f) return;
    if(h==N){
        int i;
        //for(i=0;i<N;i++) cout<<A[i]<<endl;
        for(i=0;i<K;i++){
            if(!check(S[i])) break;
        }
        if(i>=K){
            for(int j=0;j<N;j++)printf("%d",A[j]);
            printf("\n");
            f=true;
        }
        return;
    }
    for(int i=2;i<=M;i++){
        A[h]=i;
        dfs(h+1);
    }
    return;
}
int main(int argc, const char * argv[])
{
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_C/GCJ_R1A_C/C-small-1-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_C/GCJ_R1A_C/C-small-1-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        printf("Case #%d:\n",ca);
        cin>>R>>N>>M>>K;
        while(R--){
            for(int i=0;i<K;i++){
                cin>>S[i];
            }
            f=false;
            dfs(0);
        }
    }
    return 0;
}

