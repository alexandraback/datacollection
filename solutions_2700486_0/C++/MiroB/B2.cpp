#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef pair<int,int> pi;
typedef set<pi> sp;
double comb[4000][4000];
void solve() {

  int T;
  cin>>T;
  REP(c,T) {
  int x,y,n;
    cin>>n>>x>>y;
    cout.precision(7);
    int fp=1;
    int w=1;
    while(fp+w*4+1<=n) {
      fp+=4*w+1;
      w++;
    }
    int d=abs(x)+y;
    int bound=2*w-2;
    double ans=0;
    if(d<=bound) {
      ans=1.0;
    }  else if(d==bound+2) {
      int rest=n-fp;
  //    cout<<w<<" "<<rest<<endl;
      //probability ze ich na tu stranu padne aspon y
      ans=1.0;
      int want=y+1;
      int sure=max(0,rest-w*2);
      REP(i,want-sure) {
//        if(i>=rest-w*2) {
//          cout<<i<<endl;
          //cout<<rest-sure*2<<" "<<i<<endl;
          ans-=comb[rest-sure*2][i];
  //      }
      }

    }

    cout<<"Case #"<<(c+1)<<": "<<ans<<endl;
  }
}
int main() {
  int C=4000;
  REP(i,C) REP(j,C) comb[i][j]=0;
  comb[0][0]=1;
  REP(i,C) if(i) REP(j,C) comb[i][j]=(
      comb[i-1][j]+
      (j?comb[i-1][j-1]:0.0))/2.0;
//  REP(i,4) cout<<comb[3][i]<<endl;
  solve();
}
// issue choosing small type
