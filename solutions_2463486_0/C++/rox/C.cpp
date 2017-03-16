#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int aa[11111111];

bool unk2(long long a)
{
  char buf[222];
  int d = sprintf(buf,"%lld",a);
  for(int i = 0,j = d-1; i < j; i++,j--) {
    if( buf[i] != buf[j] ) return false;
  }
  return true;
}

bool unk(long long a)
{
  return unk2(a*a);
}

int sq(long long a,bool p)
{
  long long l,r,m;
  long long res = 0;
  l = 1;
  r = a;
  while(l<=r) {
    m = (l+r)/2;
    if(a==m*m)return m;
    if(a<m*m) {
      r=m-1;
      if(!p)res=m;
    } else {
      l=m+1;
      if(p)res=m;
    }
  }
  return res;
}

int main(void)
{
  int c = 0;
  for(int i = 1; i <= 10000000; i++) {
    if(unk(i) && unk2(i)){
      ++c;
    }
    aa[i]=c;
  }
  int T; scanf("%d",&T);
  for(int I = 1; I <= T; I++) {
    long long a,b;
    scanf("%lld%lld",&a,&b);
    int p,q;
    p = sq(a,false);
    q = sq(b,true);
    printf("Case #%d: %d\n",I,aa[q]-aa[p-1]);
  }
  return 0;
}
