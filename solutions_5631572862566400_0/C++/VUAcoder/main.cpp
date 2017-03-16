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

vector<int>v[1111];
int bff[1111];
int bfs(int n1, int n2){
    queue<int>q1,q2;
    q1.push(n1);
    int x=0;
    while(!q1.empty()){
        int sz = q1.size();
        for(int j=0;j<sz;j++)
        {
            int n = q1.front();
            q1.pop();
            for(int i=0;i<v[n].size();i++){
                if(v[n][i]!=n2)q1.push(v[n][i]);
            }
        }
        x++;
    }
    return x;
}
int main() {
    freopen("/Users/fchowdhu/Downloads/C-small-attempt0.in", "r", stdin);
    //freopen("/Users/fchowdhu/Downloads/C-large.in", "r", stdin);
    freopen("/Users/fchowdhu/Downloads/c.out", "w", stdout);
    int t,cn=1;
   // srand (time(NULL));

    cin>>t;
    

    while (t--) {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++) {
            v[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cin>>bff[i];
            v[bff[i]].push_back(i);
        }
        int ans=0;
        for(int c=1;c<=n;c++){
            for(int j=1;j<=n;j++)vis[j]=0;
            int i =c;
            int x=1;
         //   cerr<<"start "<<i<<endl;
            while(vis[bff[i]]==0){
               // cerr<<i<<" "<<bff[i]<<endl;
                vis[bff[i]] =x++;
                i = bff[i];
            }
            ans = max (ans,x - vis[bff[i]]);
        }
        cerr<<"here"<<endl;
        int aux =0;
        for(int i=1;i<=n;i++){
            cerr<<"i ="<<i<<endl;
            if(bff[bff[i]] == i ){
                int a = bfs(i,bff[i]) ;
                cerr<<a<<endl;
                aux += a;
            }
        }
        
        ans = max(aux, ans);
        /*vector<vector<int> >v;
        for (int i=0; i<2*n-1;  i++) {
            vector<int> temp;
            v.push_back(temp);
            for (int j=0; j<n; j++) {
                int a;
                cin>>a;
                v[i].push_back(a);
            }
        }
        sort(v.begin(),v.end());*/
        
        cout<<"Case #"<<cn++<<": "<<ans<<endl;
    }
    
    return 0;
}
