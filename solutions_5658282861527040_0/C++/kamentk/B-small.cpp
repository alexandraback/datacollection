#include<iostream>
#include<stdio.h>
using namespace std;

int main ()
{
   int a,b,k,i,j,ans=0,t,tt;

   
   freopen ("B-small-attempt1.in", "r", stdin);
   freopen ("B-small.out", "w", stdout);
   
   cin>>t;
   
   
   for(int tt=1;tt<=t;tt++)
   {
      ans=0;
      cin>>a>>b>>k;
      for(i=0;i<a;i++)
      {
         for(j=0;j<b;j++)
         {
            if((i&j)<k)
            {
               ans++;
            }
         }
      }
      printf("Case #");
      printf("%d",tt);
      printf(": ");
      printf("%d\n",ans);
   }
   //system("pause");
   return 0;
}
