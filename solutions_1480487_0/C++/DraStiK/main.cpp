#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
using namespace std;

#define MAX 100000000
#define FIN 100
#define DIM 205

double ret[DIM];
int V[DIM];
int N,T,X;

inline bool works (int player,double percent) {
  double value_player,total_percent,cur_percent;
  int i;

  value_player=(double)V[player]+percent*X;
  total_percent=1.0-percent;

  for (i=1; i<=N; ++i)
    if (i!=player) {

      if ((double)V[i]>value_player)
        continue ;

      cur_percent=(value_player-V[i])/X;
      if (cur_percent>=total_percent)
        return 1;

      total_percent-=cur_percent;
    }
  return 0;
}

void read_solve (int test) {
  int i,st,dr,mij;

  cin>>N; X=0;
  for (i=1; i<=N; ++i) {

    cin>>V[i];
    X+=V[i];
  }

  for (i=1; i<=N; ++i)
    for (st=0, dr=MAX; st<=dr; ) {
      mij=(st+dr)>>1;

      if (works (i,(double)mij/MAX)) {

        ret[i]=(double)FIN*mij/MAX;
        dr=mij-1;
      }
      else
        st=mij+1;
    }

  cout<<"Case #"<<test<<": ";
  for (i=1; i<=N; ++i)
    cout<<fixed<<setprecision (6)<<ret[i]<<" ";
  cout<<"\n";
}

int main () {
  freopen ("safety.in","r",stdin);
  freopen ("safety.out","w",stdout);
  int i;

  cin>>T;
  for (i=1; i<=T; ++i)
    read_solve (i);

  return 0;
}
