#include <algorithm>
#include <cstdio>
using namespace std;

#define DIM 105

int T,N,S,P,ret;
int V[DIM];

void read () {
  int i;

  scanf ("%d%d%d",&N,&S,&P);
  for (i=1; i<=N; ++i)
    scanf ("%d",&V[i]);
}

void solve (int test) {
  int i;

  ret=0;
  sort (V+1,V+N+1);

  for (i=N; i>=1; --i)
    if (V[i]%3==0) {

      if (V[i]/3>=P)
        ++ret;
      else if (V[i]/3 && V[i]/3+1>=P && S) {

        --S;
        ++ret;
      }
    }
    else if (V[i]%3==1) {

      if (V[i]/3+1>=P)
        ++ret;
    }
    else {

      if (V[i]/3+1>=P)
        ++ret;
      else if (V[i]/3+2>=P && S) {

        --S;
        ++ret;
      }
    }

  printf ("Case #%d: %d\n",test,ret);
}

int main () {
  freopen ("B.in","r",stdin);
  freopen ("B.out","w",stdout);

  int i;

  scanf ("%d",&T);
  for (i=1; i<=T; ++i) {

    read ();
    solve (i);
  }

  return 0;
}
