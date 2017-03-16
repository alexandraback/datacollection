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

int main(void){
  ifstream in("in.in");
  ofstream out("out.out");
  
  ll a,n,t;
  in>>t;
  
  FOR(k,t){
           
    
    ll m=99999999;
    int added=0;
    in>>a;
    in>>n;
    vi v;
    FREAD(v,n);
    sort(all(v));
    int i=0;
    if(a==1){out<<"Case #"<<k+1<<": "<<sz(v)<<endl;cout<<"Case #"<<k+1<<": "<<sz(v)<<endl;continue;}
    
    while(i<sz(v)){
      while(v[i]<a && i<sz(v)){
        a+=v[i];
        i++;              
      }
      gmin(m,sz(v)-i+added);
      added++;
      a+=a-1;
    }
    out<<"Case #"<<k+1<<": "<<m<<endl;
    cout<<"Case #"<<k+1<<": "<<m<<endl;
    
    

  }
  
  system("PAUSE");
  return 0;
}
