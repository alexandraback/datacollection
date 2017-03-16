#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

#define For(Q,W) for(int Q=0;Q<W;Q++)
#define LLD long long
#define mkp make_pair
#define pf printf
#define sf scanf

//#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

void solve(int kolko){
     cout<<"Case #"<<kolko<<": ";
     int x,y;
     cin>>x>>y;
     
     if(x>0) For(i,x) cout<<'W'<<'E';
     if(x<0) For(i,0-x) cout<<'E'<<'W';
     if(y>0) For(i,y) cout<<'S'<<'N';
     if(y<0) For(i,0-y) cout<<'N'<<'S';
     
     
     cout<<endl;
}

int T;

int main(){
    cin>>T;
    For(t,T){
         solve(t+1);    
    }
    return 0;   
}
