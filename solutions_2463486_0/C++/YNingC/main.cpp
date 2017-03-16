//
//  main.cpp
//  GCJ_Q_C
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

int id[200];
int mark[200];
long long h[1000]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
/*
bool check(long long h){
    int j;
    for(j=0;h!=0;j++){
        id[j]=h%10;
        h/=10;
    }
    j--;
    //cout<<j<<endl;
    int f=1;
    for(int k=0;k<=(j+1)/2 && f;k++){
        if(id[k]!=id[j-k]) return false;;
    }
    return true;
}
void deal(){
    int ans=0;
    for(int i=1;i<=10000000;i++){
        if(!check(i)) continue;
        long long h=(long long)i*(long long)i;
        //cout<<h<<endl;
        int j;
        for(j=0;h!=0;j++){
            id[j]=h%10;
            h/=10;
        }
        j--;
        //cout<<j<<endl;
        int f=1;
        for(int k=0;k<=(j+1)/2 && f;k++){
            if(id[k]!=id[j-k]) f=0;
        }
        h=(long long)i*(long long)i;
        if(f) cout<<h<<",";
    }
    //cout<<ans<<endl;
}*/

int main(int argc, const char * argv[])
{
    //freopen("A.in","r",stdin);
	//freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_B/GCJ_Q_B/B-large.in","r",stdin);
    //freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_B/GCJ_Q_B/B-large.out","w",stdout);
	freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_C/GCJ_Q_C/C-small-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_Q_C/GCJ_Q_C/C-small-attempt0.out","w",stdout);
    //deal();
    int T;
    long long M,N;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>N>>M;
        int ans=0;
        for(int p=0;p<39;p++){
            if(h[p]>=N && h[p]<=M) ans++;
        }
        printf("Case #%d: %d\n",ca,ans);
        //else printf("Case #%d: NO\n",ca);
    }
    
    return 0;
}

