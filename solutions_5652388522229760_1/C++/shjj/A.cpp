//shjj-A

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,now,X;

int Get(int x)
{
  int _s=0;
  for (;x;x/=10) _s|=1<<(x%10);
  return _s;
}

int main()
{
  freopen("A1.in","r",stdin);
  freopen("A1.out","w",stdout);
  int T,Tt=0;scanf("%d",&T);
  for (;T--;)
  {
    scanf("%d",&n);
    if (!n)
    {
      printf("Case #%d: INSOMNIA\n",++Tt);
      continue;
    }
    now=Get(n);
    X=n;
    for (;now!=1023;)
    {
      X+=n;
      now|=Get(X);
    }
    printf("Case #%d: %d\n",++Tt,X);
  }
}