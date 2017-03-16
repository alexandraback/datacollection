#include <stdio.h>
#include <stdlib.h>
int t,n,s,p;
int ans;
int tmp;
main()
{
 freopen("B-large.in","r",stdin);
 freopen("B-large.out","w",stdout);
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  ans=0;
  scanf("%d%d%d",&n,&s,&p);
  printf("Case #%d: ",i);
  for(int j=1;j<=n;j++)
  {
   scanf("%d",&tmp);
   if(tmp>=(3*p)-2){ans++;}
   else if(((tmp==(3*p)-3)||(tmp==(3*p)-4))&&(tmp>=2&&tmp<=28)&&s>0)
   {
    ans++;
    s--;
   }
  }
  printf("%d\n",ans);
 }
 return 0;
}
