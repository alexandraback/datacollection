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

const int maxN=1000000+13;
const int inf=0x7f7f7f7f;

int f[maxN];
int a[10];

int re(int x)
{
  int sn=0;
  while(x)
  {
    a[sn]=x%10;
    x/=10;
    sn++;
  }
  int ret=0;
  for(int i=0;i<sn;i++)
    ret=ret*10+a[i];
  return ret;
}

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.ans","w",stdout);

  memset(f,inf,sizeof(f));
  f[1]=1;
  for(int i=1;i<=1000000;i++)
  {
    upd_min(f[i+1],f[i]+1);
    upd_min(f[re(i)],f[i]+1);
  }
  int T,N;
  cin>>T;
  for(int i=1;i<=T;i++)
  {
    cin>>N;
    cout<<"Case #"<<i<<": "<<f[N]<<endl;
  }
  return 0;
}

