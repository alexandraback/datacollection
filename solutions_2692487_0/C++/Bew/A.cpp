#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int T;
int a[1000111];
int n;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int ans;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
 {
   ans=0;
   scanf("%d %d",&t,&n);
   for(i=0;i<n;i++)scanf("%d",&a[i]);
   sort(a,a+n);
   //for(i=0;i<n;i++)printf("%d ",a[i]);printf("  : %d\n",t);
   if(t==1)
    {
      ans=n;
    }
   else
    {
      q=n;
      ans=1999999999;
      for(i=0;i<n;i++)
       {
         tt=0;
         p=t;
         for(j=0;j<q;j++)
          {
            if(p>a[j])p+=a[j];
            else
             {
               while(p<=a[j])
                {
                  p+=p-1;
                  tt++;
                }
               p+=a[j];
             }
          }
         tt+=i;
         if(tt>n)tt=n;
         if(tt<ans)ans=tt;
         q--;
       }
    }
   printf("Case #%d: %d",ii,ans);
   if(ii<=T-1)printf("\n");
 }
    
    
    
    scanf(" ");
    return 0;
}
