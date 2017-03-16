#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int T;
int a,b,k;

int main()
{
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      scanf("%d%d%d",&a,&b,&k);
      int ans=0;
      for (int i=0;i<a;i++)
	for (int j=0;j<b;j++)
	  if ((i&j)<k) ans++;
      printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
