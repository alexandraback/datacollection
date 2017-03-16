#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
void solve() {
int a,b,k;
  cin>>a>>b>>k;
  int rval=0;
  REP(i,a) REP(j,b) if((j&i)<k) rval++;
  cout<<rval;
}
int main() {
int T;cin>>T;
REP(i,T) {
  cout<<"Case #"<<(i+1)<<": ";
  solve();
  cout<<endl;
}
}
