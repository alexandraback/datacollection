#include <cmath>
#include <cstdio>

long long a,t;

inline bool check(long long x)
{
  long long s;
  s=a<<1;
  s--;
  if (t/x<s) return false;
  s=s*x;
  s=s+((x*x)<<1);
  if (s<0) return false;
  if (s<=t) return true;
  return false;
}

int main()
{
  int T,o;
  long long l,r,mid;
  freopen("A-large.in","r",stdin);
  freopen("A_ans_large.txt","w+",stdout);
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    scanf("%lld%lld",&a,&t);
    r=sqrt(t>>1);
    l=1;
    while (l<r)
    {
      mid=l+r+1>>1;
      if (check(mid))
        l=mid;
      else
        r=mid-1;
    }
    printf("Case #%d: %lld\n",o,l);
  }
  return 0;
}
