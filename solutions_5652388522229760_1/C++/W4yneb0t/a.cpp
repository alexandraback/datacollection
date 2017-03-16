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
  in n;
  cin>>n;
  VI sn(10,0);
  in sct=0;
  in cn=n;
  in tp;
  while(1){
    tp=cn;
    while(tp){
      sct+=!sn[tp%10];
      sn[tp%10]=1;
      tp/=10;
    }
    if(sct==10){
      cout<<cn<<"\n";
      return;
    }
    cn+=n;
    if(cn>=100*n){
      cout<<"INSOMNIA"<<endl;
      return;
    }
  }
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
