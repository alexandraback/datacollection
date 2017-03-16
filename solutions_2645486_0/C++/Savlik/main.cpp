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
  
  FOR(k,T){
    int sum=0;
    int E,R,N;
    in>>E>>R>>N;
    vi v;
    FOR(i,N){int a;in>>a;v.pb(a);}         
    int e=E;
    
    while(sz(v)){
        int spend=0;
        if(sz(v)==1){spend=e;}else
        if(v[1]>=v[0]){
          spend=e+R-E;
          gmax(spend,0);
          gmin(spend,e);
        }else
        if(v[1]<v[0]){
          int i=1;
          while(i<sz(v) && v[i]<v[0]){i++;}
          if(i==sz(v) && v[i-1]<v[0]){spend=e;}else{
            spend=e-(E-i*R);  
            gmax(spend,0);
            gmin(spend,e);              
          }              
        }
        sum+=v[0]*spend;
        e-=spend;
        e+=R;
        v.erase(v.begin());
        //cout<<"s"<<spend<<endl;
    }
    cout<<"Case #"<<k+1<<": "<<sum<<endl;
    out<<"Case #"<<k+1<<": "<<sum<<endl;
  
  }

  system("PAUSE");
  return 0;
}
