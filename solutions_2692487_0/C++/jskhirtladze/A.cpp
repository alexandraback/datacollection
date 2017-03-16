#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

int t,k,i,j,n,answer,s,ans[200],a[200];

main()
{
 scanf("%d",&t);
 for ( k=1;k<=t;k++ )
  {
   scanf("%d%d",&s,&n);
   for ( i=1;i<=n;i++ )
    scanf("%d",&a[i]);
   sort(a+1,a+n+1);

   answer=n;

   if ( s>1 )
   for ( i=1;i<=n;i++ )
    {
     ans[i]=ans[i-1];
     if ( s>a[i] ) s+=a[i];
      else
       {
        while ( s<=a[i] )
         {
          s+=s;
          s-=1;
          ans[i]++;
         }
        s+=a[i];
       }

     answer=min(answer,ans[i]+n-i);
    }

   if ( s==1 ) answer=n;

   printf("Case #%d: %d\n",k,answer);
  }
}
