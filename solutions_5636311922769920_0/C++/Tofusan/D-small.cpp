#include <stdio.h>
#include <stdlib.h>

int t;
long long k,c,s;
long long ans;
long long pri;
main()
{
 freopen("D-small-attempt0.in","r",stdin);
 freopen("D-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%I64d%I64d%I64d",&k,&c,&s);
  ans=1;
  for(int i=1;i<c;i++)
  {
   ans=(long long)ans*k;
  }
  printf("Case #%d: ",tests);
  pri=1;
  for(int i=1;i<=s;i++)
  {
   printf("%I64d",pri);
   if(i!=s){printf(" ");}
   else{printf("\n");}
   pri=pri+ans;
  }
  //printf("\n");
 }
 return 0;
}
