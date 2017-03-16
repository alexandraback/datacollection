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
VI p;
int main(){
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    in d;
    cin>>d;
    p.resize(d);
    forn(i,d)
      cin>>p[i];
    in bst=1000000;
    in cr;
    for(in mx=1;mx<=1000;mx++){
      cr=mx;
      forv(i,p){
	cr+=(p[i]-1)/mx;
      }
      if(cr<bst)bst=cr;
    }
    cout<<"Case #"<<zz<<": ";
    cout<<bst<<endl;
  }
  return 0;
}
