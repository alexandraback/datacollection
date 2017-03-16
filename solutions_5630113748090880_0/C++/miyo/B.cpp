#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

template <typename T>
inline void upd_max(T &dest,const T& src){if(dest<src)dest=src;return ;}
template <typename T>
inline void upd_min(T &dest,const T& src){if(dest>src)dest=src;return ;}

const int maxN=2500+13;

int T,N;
int s[maxN];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("B-small-attempt0 (1).in","r",stdin);
  freopen("B.out","w",stdout);
#endif
  scanf("%d",&T);
  int tt;
  for(int cas=1;cas<=T;cas++)
  {
    scanf("%d",&N);
    memset(s,0,sizeof(s));
    for(int i=1;i<=2*N-1;i++)
    {
      for(int j=1;j<=N;j++)
      {
        scanf("%d",&tt);
        s[tt]++;
      }
    }
    printf("Case #%d:",cas);
    for(int i=1;i<=2500;i++)
    {
      if(s[i]&1)
        printf(" %d",i);
    }
    printf("\n");
  }

  return 0;
}

