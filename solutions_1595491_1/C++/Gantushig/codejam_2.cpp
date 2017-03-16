#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string.h>
#include<math.h>

using namespace std;

int n,i,t,s,p,j,x,l1,l2,l3,s1;

main()
{
  freopen("g1.in","r",stdin);
  freopen("g1.out","w",stdout);
  
  scanf("%d",&t);
  for (i=1;i<=t;i++)      
  {
    scanf("%d%d%d",&n,&s,&p);  
    s1=0;
    for (j=1;j<=n;j++)
    {
      scanf("%d",&x);
      l1=l2=l3=x/3;  
      if (x%3==2) 
      {
        l1++;
        l2++;
        if (l1>=p) s1++;
          else
          {
            if (s>0)
            {
              l1++;
              if (l1>=p) {s1++;s--;}      
            }  
          }
      } else if (x%3==1) {l1++;if (l1>=p) s1++;}
               else if (l1>=p) s1++; 
                 else if (l1>0)
                 {
                   if (s>0)
                   {
                     l1++;
                     if (l1>=p) {s1++; s--;}     
                   }  
                 }
    }
    printf("Case #%d: %d\n",i,s1);
  }
}
