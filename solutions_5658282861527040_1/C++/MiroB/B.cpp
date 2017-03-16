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
  int A,B,K;
  int n=31;
  cin>>A>>B>>K;
  vector<int> a(n),b(n),k(n);
  REP(i,n) {
    a[i]=!!(A&( 1<<i));
    b[i]=!!(B&( 1<<i));
    k[i]=!!(K&( 1<<i));

  }
  long long int h[2][2][2];
  REP(i,2) REP(j,2) REP(l,2) h[i][j][l]=0;
  h[0][0][0]=1;
  for(int pos=n-1;pos>=0;--pos) {
    int x[2][2][2];
    REP(i,2) REP(j,2) REP(l,2) x[i][j][l]=0;
    int bita=a[pos];
    int bitb=b[pos];
    int bitk=k[pos];
    REP(puta,2) {
      REP(putb,2) {
        REP(as,2) REP(bs,2) REP(ks,2) {
          if(!as && puta>bita) continue;
          int nas=as || puta<bita;
          if(!bs && putb>bitb) continue;
          int nbs=bs || putb<bitb;
          int put=puta&putb;
          if(!ks && put>bitk) continue;
          int nks=ks || put<bitk;
          x[nas][nbs][nks]+=h[as][bs][ks];
        }
      }
    }

    REP(i,2) REP(j,2) REP(l,2) h[i][j][l]=x[i][j][l];
  }
  cout<<h[1][1][1];

}
int main() {
  int T;cin>>T;
  REP(i,T) {
    cout<<"Case #"<<(i+1)<<": ";
    solve();
    cout<<endl;
  }
}
