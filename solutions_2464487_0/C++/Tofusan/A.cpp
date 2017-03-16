#include <stdio.h>
#include <stdlib.h>

int t;
long long r,s;
long long tmp1,tmp2,tmp3,tmp4;
void search()
{
 long long l=1,rr,mids,ans;
 rr=1;
 for(int i=1;i<=9;i++)
 {
  rr=(long long)rr*10;
 }
 rr=rr+1;
 tmp4=(long long)s/r;
 tmp4=tmp4+1;
 if(tmp4<rr){rr=tmp4;}
 while(l<=rr)
 {
  mids=(long long)(l+rr)/2;
  tmp2=(long long)mids*mids;
  tmp2=(long long)tmp2*2;
  tmp3=(long long)mids*2;
  tmp4=(long long)tmp3*r;
  tmp1=tmp2+tmp4;
  //printf("%I64d\n",tmp1);
  tmp1=tmp1-mids;
  //printf("%I64d %I64d %I64d %I64d\n",mids,tmp2,tmp4,tmp1);
  //printf("%I64d %I64d\n",l,rr);
  if(tmp1<=s)
  {
   ans=mids;
   l=mids+1;
  }
  else
  {
   rr=mids-1;
  }
 }
 printf("%I64d\n",ans);
}
main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("A-small.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%I64d%I64d",&r,&s);
  printf("Case #%d: ",tests);
  search();
 }

 return 0;
}
