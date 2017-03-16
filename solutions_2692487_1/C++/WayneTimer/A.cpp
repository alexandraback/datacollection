#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000100];
long long s;
int n,ans;

inline void work()
{
  int i,t,k;
  sort(a+1,a+1+n);
  i=1;
  ans=n;
  t=0;
  while (i<=n)
  {
    while (i<=n && s>a[i])
    {
      s+=a[i];
      i++;
    }
    if (i>n)
    {
      if (t<ans) ans=t;
      break;
    }
    k=n-i+1;
    if (t+k<ans) ans=t+k;
    if (s-1==0) break;
    s+=s-1;
    t++;
  }
  printf("%d\n",ans);
}

int main()
{
  int T,o,i;
  freopen("A-large.in","r",stdin);
  freopen("A_ans_large.txt","w+",stdout);
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    scanf("%lld %d",&s,&n);
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    printf("Case #%d: ",o);
    work();
  }
  return 0;
}
