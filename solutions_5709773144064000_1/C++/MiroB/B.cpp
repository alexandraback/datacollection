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
  double c,f,x;
  cin>>c>>f>>x;
  double time=0;
  double rval=x/2.0;
  //time for waiting decreases and time improvement decreases
  double spd=2.0;
  while(true) {
    time+=c/spd;
    spd+=f;
    if(time+x/spd>rval) break;
    rval=time+x/spd;
  }
  cout.precision(8);
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
