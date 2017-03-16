#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

#define pb push_back
#define DIM 1005

vector <int> G[DIM];
int f[DIM];
int T,N;

void df (int nod) {
  vector <int> :: iterator it;

  ++f[nod];
  for (it=G[nod].begin (); it!=G[nod].end (); ++it)
    df (*it);
}

void read_solve (int test) {
  int i,j,x,nrx;

  cin>>N;
  for (i=1; i<=N; ++i) {

    cin>>nrx;
    G[i].clear ();
    for (j=1; j<=nrx; ++j) {

      cin>>x;
      G[i].pb (x);
    }
  }

  for (i=1; i<=N; ++i) {

    memset (f,0,sizeof (f));
    df (i);

    for (j=1; j<=N; ++j)
      if (f[j]>1) {

        cout<<"Case #"<<test<<": Yes\n";
        return ;
      }
  }
  cout<<"Case #"<<test<<": No\n";
}

int main () {
  freopen ("diamond.in","r",stdin);
  freopen ("diamond.out","w",stdout);
  int i;

  cin>>T;
  for (i=1; i<=T; ++i)
    read_solve (i);

  return 0;
}
