#include <stdio.h>
#include <stdlib.h>

int t;
int n;
bool A[10];
int cnt;
int nows;
int nexts;
int dig;
void clear()
{
 cnt=10;
 for(int i=0;i<=9;i++)
 {
  A[i]=false;
 }
}
main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("A-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d",&n);
  clear();
  printf("Case #%d: ",tests);
  if(n==0){printf("INSOMNIA\n");}
  else
  {
   nows=n;
   while(cnt>0)
   {
    nexts=nows+n;
    while(nows>0)
    {
     dig=nows%10;
     if(A[dig]==false){A[dig]=true;cnt--;}
     nows=nows/10;
    }
    if(cnt==0){printf("%d\n",nexts-n);}
    else{nows=nexts;}
   }
  }
 }
 return 0;
}
