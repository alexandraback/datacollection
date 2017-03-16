#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;

void docase(){
  in k,c,s;
  cin>>k>>c>>s;
  if(s*c<k){
    cout<<"IMPOSSIBLE"<<endl;
    return;
  }
  VI nbs(s,0);
  VI pw(c+1);
  pw[0]=1;
  for(in i=1;i<=c;++i)
    pw[i]=pw[i-1]*k;
  forn(i,k){
    nbs[i%s]+=i*pw[i/s];
  }
  forn(i,s)
    cout<<nbs[i]+1<<" ";
  cout<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    docase();
  }
  return 0;
}
