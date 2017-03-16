//
//  main.cpp
//  GCJ_Q_B
//
//  Created by Ningchen Ying on 4/13/13.
//  Copyright (c) 2013 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

int ync[200][200];
int mmax[200];
int id[200];
int mark[200];

int main(int argc, const char * argv[])
{
    //freopen("A.in","r",stdin);
	//freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_A/GCJ_Q_A/A-large.in","r",stdin);
    //freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_A/GCJ_Q_A/A-large.out","w",stdout);
	freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_B/GCJ_Q_B/B-small-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_B/GCJ_Q_B/B-small-attempt0.out","w",stdout);
    int T,M,N;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>N>>M;
        for(int i=0;i<M;i++) mark[i]=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&ync[i][j]);
                if(j==0) mmax[i]=ync[i][j];
                else mmax[i]=max(mmax[i],ync[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            //cout<<mmax[i]<<endl;
            for(int j=0;j<M;j++){
                if(ync[i][j]<mmax[i]) mark[j]=1;
            }
        }
        //for(int i=0;i<M;i++) cout<<mark[i]<<" ";;
        //cout<<endl;
        int flag=1;
        for(int i=0;i<M && flag;i++){
            if(mark[i]==0) continue;
            for(int j=1;j<N && flag;j++){
                if(ync[j][i]!=ync[j-1][i]) flag=0;
            }
        }
        if(flag==1) printf("Case #%d: YES\n",ca);
        else printf("Case #%d: NO\n",ca);
    }
    
    return 0;
}

