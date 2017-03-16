//
//  main.cpp
//  codejam_2016
//
//  Created by fchowdhu on 4/9/16.
//  Copyright © 2016 fchowdhu. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;

typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;
map<long long, int > vis;
/*int N=32;
long long getRand(){
    long long msk = (1LL<<(N-1))+1;
    for(long long i=1;i<(N-1);i++){
        msk |= (rand()%2LL)<<i;
    }
    if(vis[msk]==0){
        vis[msk]=1;
    }else return getRand();
    return msk;
}
long long getBase(long long x, long long b){
    long long l=1,ans=0;
    for(int i=0;i<N;i++){
        if(x&(1LL<<i)){
            ans+=l;
        }
        l*=b;
    }
    return ans;
}
bool getBasePrime(long long x,long long b, long long m){
    long long l=1,ans=0;
    for(int i=0;i<N;i++){
        if(x&(1LL<<i)){
            ans+=l;
            ans%=m;
        }
        l*=b;
        l%=m;
    }
    return ans;
    
}
long long prime(long long x,long long b){
    
    for(long long i=3;i*i<=10000;i+=2){
        if(getBasePrime(x,b,i) ==0)return i;
    }
    return 0;
}

bool check (long long x){
    
    vector<long long >v;
    for(long long i=2;i<=10;i++){
        //long long y = getBase(x,i);

        long long z = prime(x,i);
        //cerr<<x<<" "<<y<<" "<<z<<endl;
        if(z){
          //  if(y%z)cerr<<"ERROR "<<y<<" "<<z<<endl;
            v.push_back(z);
        }else return false;
    }
    for(int i=(N-1);i>=0;i--){
        if(x&(1LL<<i)){
            cout<<"1";
        }
        else cout<<"0";
    }
    for(int i=0;i<v.size();i++){
        
        cout<<" "<<v[i];
    }
    cout<<endl;
    return true;
    
}*/
int main() {
    //freopen("/Users/fchowdhu/Downloads/D-small-attempt0.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/D-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/dl.out", "w", stdout);
    long long l=0;
    int t,cn=1;
   // srand (time(NULL));

    cin>>t;
    //cout<<"Case #"<<cn++<<":"<<endl;

    while (t--) {
      /*  int c=0;
        long long n,j;
        cin>>n>>j;
        while(1){
            
            long long x = getRand();
            cerr<<x<<endl;
            if(check(x)){
                c++;
                cerr<<"---"<<c<<"---"<<endl;
            }
            if(c==500)break;
        }
        */
        long long K,C,S;
        cin>>K>>C>>S;
        long long po[222];
        po[0]=1;
        for (int k=1; k<C; k++) {
            po[k] = po[k-1]*K;
        }
        int Y=0;
        vector<long long>v;
        for(int k=0;k<K;k+=C){
            long long X=0;
            for(int l=0;l<C;l++){
                if(Y<K){
                    X += po[C-l-1]*Y;
                    Y++;
                }
            }
            v.push_back(X+1);
        }
        cout<<"Case #"<<cn++<<":";
        
        if(v.size()<=S){
            for (int i=0; i<v.size(); i++) {
                cout<<" "<<v[i];
            }
            cout<<endl;
        }else{
            cout<<" IMPOSSIBLE"<<endl;
        }
        
        
    }
    
    return 0;
}
