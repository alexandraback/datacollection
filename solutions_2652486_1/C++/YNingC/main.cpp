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
int T,R,N,M,K,MM;
int S[20];
int A[20];
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
    if(h>=N){
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
    
    for(int i=2;i<=MM;i++){
        //if(i==5 || i==7 |) continue;
        A[h]=i;
        dfs(h+1);
    }
    return;
}
int main(int argc, const char * argv[])
{
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_C/GCJ_R1A_C/C-small-2-attempt1.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_C/GCJ_R1A_C/C-small-2-attempt1.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        printf("Case #%d:\n",ca);
        cin>>R>>N>>M>>K;
        if(M>=5) MM=4;
        else MM=M;
        while(R--){
            for(int i=0;i<K;i++){
                cin>>S[i];
            }
            int h=0;
            int w=0,q=0,l=0,b=0;
            for(int i=0;i<K;i++){
                int tp=S[i];
                int ww=0;
                while(tp%5==0){
                    tp/=5;
                    ww++;
                }
                tp=S[i];
                int qq=0;
                while(tp%7==0){
                    tp/=7;
                    qq++;
                }
                
                int ll=0;
                if(M>=6){
                    tp=S[i];
                    while(tp%6==0){
                        tp/=6;
                        ll++;
                    }
                }
                
                int bb=0;
                if(M>=8){
                    tp=S[i];
                    while(tp%8==0){
                        tp/=8;
                        bb++;
                    }
                }
                w=max(w,ww);
                q=max(q,qq);
                l=max(l,ll);
                b=max(b,bb);
            }
            for(int i=0;i<w;i++)A[i]=5;
            for(int i=w;i<w+q;i++)A[i]=7;
            for(int i=w+q;i<w+q+b;i++)A[i]=8;
            for(int i=w+q+b;i<w+q+b+l;i++)A[i]=6;
            h=w+q+b+l;
            f=false;
            dfs(h);
            if(!f){
                for(int i=0;i<N;i++){
                    printf("%d",A[i]);
                }printf("\n");
            }
        }
    }
    return 0;
}

