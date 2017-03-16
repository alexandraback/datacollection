#include <cstdio>
#include <cstring>

int s[3000];
int a,b,k;

int main()
{
  int T,o,i,j;
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    printf("Case #%d: ",o);
    scanf("%d %d %d",&a,&b,&k);
    memset(s,0,sizeof(s));
    for (i=0;i<a;i++)
      for (j=0;j<b;j++)
      {
	s[i&j]++;
      }
    int ans=0;
    for (i=0;i<k;i++)
      ans+=s[i];
    printf("%d\n",ans);
  }
  return 0;
}
