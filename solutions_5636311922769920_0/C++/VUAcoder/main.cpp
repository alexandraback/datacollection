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

int main() {
    freopen("/Users/fchowdhu/Downloads/D-small-attempt0.in", "r", stdin);
    //freopen("/Users/fchowdhu/Downloads/B-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/d.out", "w", stdout);
    long long l=0;
    int t,cn=1;
    cin>>t;
    while (t--) {
        long long K,C,S;
        cin>>K>>C>>S;
        
        
        cout<<"Case #"<<cn++<<":";
        
        long long k=1;
        for(int i=0;i<C-1;i++){
            k*=K;
        }
        long long X =1;
        for(int i=0;i<S;i++){
            
            cout<<" "<<X;
            X+=k;
        }
        cout<<endl;
    }
    
    return 0;
}
