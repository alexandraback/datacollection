#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (int i = 0; i < int(n); i++)
#define READ(v,n) { FOR(i,n){int x;cin>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(void){
  ifstream in("in.in");
  ofstream out("out.out");

  int T;
  in>>T;
  ull r,t;
  
  FOR(k,T){
    in>>r>>t;         
    ull f=r*2+1;
    ull sum=f;
    ull num=0;
    while(sum<=t){f=f+4;sum+=f;num++;}
    out<<"Case #"<<k+1<<": "<<num<<endl;
  }
  
  

  system("PAUSE");
  return 0;
}
