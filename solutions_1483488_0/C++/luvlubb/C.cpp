#include <stdio.h>
#include <stdlib.h>
int a,b,t;
int tmp,lastd;
int A[21];
int cnt;
int ans;
int digits;
int mul;
bool confl;
main()
{
 freopen("C-small-attempt0.in","r",stdin);
 freopen("C-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int i=1;i<=t;i++)
 {
  printf("Case #%d: ",i);
  scanf("%d%d",&a,&b);
  ans=0;
  tmp=a;
  mul=1;
  digits=0;
  while(tmp!=0)
  {
   tmp=tmp/10;
   digits++;
  }
  for(int j=1;j<digits;j++)
  {
    mul=mul*10;
  }
  for(int j=a;j<b;j++)
  {
   cnt=0;
   tmp=j;
   for(int k=1;k<digits;k++)
   {
    lastd=tmp%10;
    tmp=tmp/10;
    tmp=tmp+(lastd*mul);
    /*printf("%d\n",tmp);
    system("pause");*/
    if(tmp>j&&tmp<=b)
    {
     //printf("in1\n");
     //system("pause");
     confl=false;
     for(int l=1;l<=cnt;l++)
     {
       if(tmp==A[l]){confl=true;break;}
     }
     if(confl==false)
     {
      //printf("in2\n");
      //system("pause");
      cnt++;
      A[cnt]=tmp;
     }
    }
   }
   ans+=cnt;
   //printf("%d : cnt = %d ans = %d\n",j,cnt,ans);
   //system("pause");
  }
  printf("%d\n",ans);
 }
 return 0;
}
