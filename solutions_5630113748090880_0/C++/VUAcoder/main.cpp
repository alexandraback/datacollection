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

int cnt[2555];

int main() {
    freopen("/Users/fchowdhu/Downloads/B-small-attempt0.in", "r", stdin);
    //freopen("/Users/fchowdhu/Downloads/B-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/B.out", "w", stdout);
    int t,cn=1;
   // srand (time(NULL));

    cin>>t;
    

    while (t--) {
        int n;
        cin>>n;
        for (int i=0; i<=2510;  i++) {
            cnt[i]=0;
        }
        vector<vector<int> >v;
        for (int i=0; i<2*n-1;  i++) {
            for (int j=0; j<n; j++) {
                int a;
                cin>>a;
                cnt[a]++;
            }
        }
        
        
        
        
        cout<<"Case #"<<cn++<<":";
        for (int i=0; i<=2510;  i++) {
            if(cnt[i]&1)cout<<" "<<i;
        }
        cout<<endl;
    }
    
    return 0;
}
