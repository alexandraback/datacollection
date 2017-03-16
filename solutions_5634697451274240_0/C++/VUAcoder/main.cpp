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
    freopen("/Users/fchowdhu/Downloads/B-small-attempt0.in", "r", stdin);
    //freopen("/Users/fchowdhu/Downloads/A-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/b.out", "w", stdout);
    long long l=0;
    int t,cn=1;
    cin>>t;
    while (t--) {
        string str;
        cin>>str;
        int c=0;
        for (int i=0; i<str.size()-1; i++) {
            if(str[i]!=str[i+1]){
                c++;
            }
        }
        if(str[str.size()-1]=='-')c++;
        
        cout<<"Case #"<<cn++<<": "<<c<<endl;
    }
    
    return 0;
}
