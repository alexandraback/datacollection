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
    int x,y;
    in>>x>>y;
    vector <pair <pair <int, int> ,string> > v,v2;
    v.pb(mp(mp(0,0),""));
    int j=1;
    while(true){
      sort(all(v));
      //cout<<j<<":"<<endl;
      int lx,ly;
      FOR(i,sz(v)){
        if(i>0){if(lx==v[i].first.first && ly==v[i].first.second){continue;}}
        lx=v[i].first.first;
        ly=v[i].first.second;
        //cout<<v[i].first.first<<","<<v[i].first.second<<","<<v[i].second<<endl;
        if(v[i].first.first==x && v[i].first.second==y){OUT(t,v[i].second);goto end;}
        v2.pb(mp(mp(v[i].first.first,v[i].first.second+j),v[i].second+"N"));            
        v2.pb(mp(mp(v[i].first.first+j,v[i].first.second),v[i].second+"E"));
        v2.pb(mp(mp(v[i].first.first,v[i].first.second-j),v[i].second+"S"));
        v2.pb(mp(mp(v[i].first.first-j,v[i].first.second),v[i].second+"W"));
      }   
      v=v2;
      v2.clear();
        //system("PAUSE");
      j++;    
    }
             
     end:true;      
  
  }
  
  system("PAUSE");
  return 0;
}
