#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string.h>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (int i = 0; i < int(n); i++)
#define READ(v,n) { FOR(i,n){int x;cin>>x;v.pb(x);} }
#define FREAD(v,n) { FOR(i,n){int x;in>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define FWRITE(v) "";FOR(i,sz(v))out<<v[i]<<" ";out
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
#define OUT(k,i) { out<<"Case #"<<k+1<<": "<<i<<endl; }
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int main(void){
  ifstream in("in.in");
  ofstream out("out.out");
  
  int T;
  in>>T;
  FOR(t,T){
    int N;
    in>>N;
    vi d,n,w,e,s,dd,dp,ds;
    FOR(i,N){
      int x;
      in>>x;d.pb(x);       
      in>>x;n.pb(x);
      in>>x;w.pb(x+500);
      in>>x;e.pb(x+500);
      in>>x;s.pb(x);      
      in>>x;dd.pb(x);      
      in>>x;dp.pb(x);      
      in>>x;ds.pb(x);  
    }       
    int time=0;
    vi wall(1000,0);  
    vi wall2(1000,0);
    int suc=0;
    
    while(time<=676060){
    
    wall2=wall;
    FOR(i,N){
      if(d[i]<=time && (time-d[i])%dd[i]==0 && (time-d[i])/dd[i]<=n[i]-1 ){
              //attack
        int l=w[i]+dp[i]*((time-d[i])/dd[i]);              
        int r=e[i]+dp[i]*((time-d[i])/dd[i]);
        int str=s[i]+ds[i]*((time-d[i])/dd[i]);
        for(int j=l;j<r;j++){
          if(wall[j]<str){suc++;for(int j=l;j<r;j++){wall2[j]=max(wall2[j],str);}break;}
        }
        cout<<time<<","<<i<<","<<l<<","<<r<<","<<str<<","<<suc<<endl;
      }         
    } 
    wall=wall2;      
    time++;
    }
    OUT(t,suc);cout<<endl;
           
  }

  system("PAUSE");
  return 0;
}
