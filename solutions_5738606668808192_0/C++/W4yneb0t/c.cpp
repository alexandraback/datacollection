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
in fdv(string& s, in b){
  const in mx=100;
  for(in d=2;d<=mx;++d){
    in nb=0;
    forv(i,s){
      nb*=b;
      nb+=(s[i]-'0');
      nb%=d;
    }
    if(nb==0){
      return d;
    }
  }
  return -1;
}
set<string> usd;
vector<string> sts;
VVI dvs;
bool genst(in n){
  string rs="1";
  forn(i,n-2)
    rs+=char('0'+rand()%2);
  rs+='1';
  if(usd.find(rs)!=usd.end())
    return 0;
  VI dv(9);
  for(in i=2;i<=10;++i){
    dv[i-2]=fdv(rs,i);
    if(dv[i-2]==-1)
      return 0;
  }
  sts.PB(rs);
  dvs.PB(dv);
  usd.insert(rs);
  return 1;
}
void docase(){
  usd.clear();
  sts.clear();
  dvs.clear();
  in n,j;
  cin>>n>>j;
  while(j){
    if(genst(n))
      --j;
  }
  forv(i,sts){
    cout<<sts[i];
    forv(j,dvs[i])
      cout<<" "<<dvs[i][j];
    cout<<endl;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<":"<<endl;
    docase();
  }
  return 0;
}
