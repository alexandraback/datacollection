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
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double fact(double v){
  if(v==0)return (double)1;
  return v*fact(v-1);
}

double comb(double n,double k){
  return fact(n)/(fact(k)*fact(n-k));
}

int main(void){
  ifstream in("in.in");
  ofstream out("out.out");
  int t;
  
  in>>t;
  
  FOR(k,t){
    int n,x,y;
    in>>n>>x>>y;
    int ord=y+1;
    
    int size=3;
    n--;           
        
    while(2*size-1<=n){n-=2*size-1;size+=2;}   
    if(abs(x)+y<=size-3){out<<"Case #"<<k+1<<": 1.0"<<endl; continue;}
    if(abs(x)+y>size){out<<"Case #"<<k+1<<": 0.0"<<endl; continue;}
    double all, good;
    all=0;
    good=0;
    if(n==0){out<<"Case #"<<k+1<<": 0.0"<<endl; continue;}
    if(size==ord){out<<"Case #"<<k+1<<": 0.0"<<endl; continue;}
    FOR(i,n+1){
      if(n-i<size && i<size){
        all+=comb(n,i);
        if(i>=ord){good+=comb(n,i);}            
      }
    }
    if(all==0){out<<"Case #"<<k+1<<": 0.0"<<endl; continue;}
    if(good==0){out<<"Case #"<<k+1<<": 0.0"<<endl; continue;}

    //out<<good<<","<<all<<",";
    
    if(good==all){out<<"Case #"<<k+1<<": 1.0"<<endl; continue;}
    
    out<<"Case #"<<k+1<<": "<<good/all<<endl; continue;
    
  }

  
  system("PAUSE");
  return 0;
}
