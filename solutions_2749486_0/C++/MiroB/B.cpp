#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
int main() {
  int T;cin>>T;
  REP(tt,T) {
    cout<<"Case #"<<(tt+1)<<": ";
    int x,y;
    string sx("WE"),sy("SN");
    cin>>x>>y;
    if(x<0) {
      x=-x;
      swap(sx[0],sx[1]);
    }
    if(y<0) {
      swap(sy[0],sy[1]);
      y=-y;
    }
    REP(i,x) cout<<sx;
    REP(i,y) cout<<sy;
    cout<<endl;
  }
}
// issue choosing small type
