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
    //freopen("/Users/fchowdhu/Downloads/A-small-attempt0.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/A-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/al.out", "w", stdout);
    long long l=0;
    int t,cn=1;
    cin>>t;
    //t=1000001;
    long long n=0;
    while (t--) {
        //n++;
        cin>>  n;
        
        if (n==0) {
            cout<<"Case #"<<cn++<<": INSOMNIA"<<endl;
            continue;
        }
        int msk =0;
        for (int i=1; ; i++) {

            long long x = n*i;
            char str[111];
            sprintf(str, "%lld",x);
            for(int j=0;j<strlen(str);j++){
                msk |=1<<(str[j]-'0');
            }
             //           cout<<str<<endl;
            if(__builtin_popcount(msk) == 10){
                cout<<"Case #"<<cn++<<": "<<x<<endl;
                break;
            }
        }
    }
    
    return 0;
}
