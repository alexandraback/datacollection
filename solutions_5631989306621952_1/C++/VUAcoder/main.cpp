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

int main() {
    //freopen("/Users/fchowdhu/Downloads/A-small-attempt0.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/A-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/al.out", "w", stdout);
    int t,cn=1;
   // srand (time(NULL));

    cin>>t;
    

    while (t--) {
        string str;
        cin>>str;
        string ans;
        for(int i=0;i<str.size();i++){
            if(ans.size()==0){
                ans+=str[i];
            }else if(ans[0]>str[i])
            {
                ans+=str[i];
            }else{
                ans=str[i] + ans;
            }
        }
        cout<<"Case #"<<cn++<<": "<<ans<<endl;
    }
    
    return 0;
}
