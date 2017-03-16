#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define DIM 25

map <int,int> H;
int V[DIM];
int N,T;

void read_solve (int test) {
  int stare,newstare,i,suma;

  cin>>N;
  for (i=0; i<N; ++i)
    cin>>V[i];
  H.clear ();

  for (stare=1; stare<(1<<N); ++stare) {

    suma=0;
    for (i=0; i<N; ++i)
      if (stare&(1<<i))
        suma+=V[i];

    newstare=H[suma];
    if (newstare) {

      cout<<"Case #"<<test<<":\n";
      for (i=0; i<N; ++i)
        if (stare&(1<<i))
          cout<<V[i]<<" ";
      cout<<"\n";
      for (i=0; i<N; ++i)
        if (newstare&(1<<i))
          cout<<V[i]<<" ";
      cout<<"\n";

      return ;
    }
    H[suma]=stare;
  }
  cout<<"Case #"<<test<<":\nImpossible\n";
}

int main () {
  freopen ("equal.in","r",stdin);
  freopen ("equal.out","w",stdout);
  int i;

  cin>>T;
  for (i=1; i<=T; ++i)
    read_solve (i);

  return 0;
}
