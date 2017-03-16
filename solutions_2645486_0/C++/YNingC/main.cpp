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
long long ans;
int val[100];
long long minn(long long A,long long B){
    if(A>B)return B;
    return A;
}
int main(int argc, const char * argv[]){
    int E,R,N;
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_B/GCJ_R1A_B/B-small-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_B/GCJ_R1A_B/B-small-attempt0.out","w",stdout);
    
    int T;
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        scanf("%d%d%d",&E,&R,&N);
        ans = 0;
        for (int i=0;i<N;i++) scanf("%d",&val[i]);
        memset(f,-1,sizeof(f));
        f[0][E] = 0;
        for(int i=0;i<=N;i++){
            for (int j = 0;j<=E;j++){
                if (f[i][j]>-1){
                    if (i==N){
                        ans = max(ans,f[i][j]);
                        continue;
                    }
                    for (long long cost = 0;cost<=j;cost++){
                        long long tmp = minn((long long)(j-cost+R),(long long)E);
                        f[i+1][(int)tmp] = max(f[i+1][(int)tmp],f[i][j]+cost*val[i]);
                    }
                }
            }
        }
        printf("Case #%d: ",ca);
        cout<<ans<<endl;
    }
}