//
//  main.cpp
//  GCJ_R1A_B
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

long long f[100][100];
long long ans,cnt,tmp;
int V[11020];
int E,R,N;
long long minn(long long A,long long B){
    if(A>B)return B;
    return A;
}
int linked[11000];
void solve(){
    linked[N]=N;
    for(int i=N-1;i>=0;i--){
        int j;
        for(j=i+1;j<N && V[j]<V[i];j=linked[j]);
        linked[i]=j;
    }
    for(int i=0;i<N;i++){
        tmp=0;
        if (linked[i]==N) tmp=cnt;
        else tmp = max((long long)0,(long long)(linked[i]-i)*R+cnt-E);
        tmp = min(cnt,tmp);
        cnt-=tmp;cnt+=R;
        ans+=tmp*V[i];
    }
}
int main(int argc, const char * argv[]){

    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_B/GCJ_R1A_B/B-large.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_B/GCJ_R1A_B/B-large.out","w",stdout);
    
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>E>>R>>N;
        ans = 0;
        cnt = E;
        for (int i=0;i<N;i++) scanf("%d",&V[i]);
        solve();
        
        printf("Case #%d: ",ca);
        cout<<ans<<endl;
    }
}