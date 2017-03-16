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
int main(){
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    in n;
    string s;
    cin>>n>>s;
    in sf=0;
    in gv=0;
    forn(i,sz(s)-1){
      sf+=s[i]-'0';
      if(sf<1){
	gv++;
	sf++;
      }
      sf--;
    }
    cout<<gv<<endl;
  }
  return 0;
}
