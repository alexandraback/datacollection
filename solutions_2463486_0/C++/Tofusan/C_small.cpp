#include <stdio.h>
#include <stdlib.h>

int t;
long long tmp;
long long ans[1000001];
long long digits[20];
int cnt;
long long st,ed;
bool chk(long long a)
{
 int digs=0;
 while(a!=0)
 {
  digs++;
  digits[digs]=(long long)a%10;
  a=(long long)a/10;
 }
 for(int i=1;i<=digs/2;i++)
 {
  if(digits[i]!=digits[digs-i+1]){return false;}
 }
 return true;
}
void gen()
{
 for(int i=1;i<=10000001;i++)
 {
  if(chk(i))
  {
   tmp=(long long)i*i;
   if(chk(tmp))
   {
    cnt++;
    ans[cnt]=tmp;
    //printf("%d %I64d\n",i,tmp);
   }
  }
 }
}
int search1(long long a)
{
 int l=1,r=cnt,mids,ret=cnt;
 while(l<=r)
 {
  mids=(l+r)/2;
  if(ans[mids]<a){l=mids+1;}
  else{r=mids-1;ret=mids;}
 }
 return ret;
}
int search2(long long a)
{
 int l=1,r=cnt,mids,ret=1;
 while(l<=r)
 {
  mids=(l+r)/2;
  if(ans[mids]>a){r=mids-1;}
  else{l=mids+1;ret=mids;}
 }
 return ret;
}
int solve()
{
 int ss,ee;
 ss=search1(st);
 ee=search2(ed);
 return ee-ss+1;
}
main()
{
 freopen("C-small-attempt0.in","r",stdin);
 freopen("C-small.out","w",stdout);
 gen();
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%I64d%I64d",&st,&ed);
  printf("Case #%d: %d\n",tests,solve());
 }
 return 0;
}
