#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string.h>
#include<math.h>

using namespace std;

int a,b,s,s1,x,i,j,t,l,k,m,z,as;
map <pair<int, int>, int> AA;

main()
{
  freopen("g1.in","r",stdin);
  freopen("g1.out","w",stdout);
  
  scanf("%d",&t);
  for (i=1;i<=t;i++)      
  {
    scanf("%d%d",&a,&b);
    x=b;
    s=0;
    s1=1;
    as=0;
    while (x!=0)
    {
      s1=s1*10;
      as++;
      x=x/10;    
    }
    s1=s1/10;
    AA.clear();
    for (j=a;j<b;j++)  
    {
      m=j;  
      for (z=1;z<as;z++)  
      {
        l=m/s1;
        k=m%s1;
        m=k*10+l;
        if ((j<m)&&(m<=b)) 
        {
          if (AA[pair<int, int>(j,m)]!=1) {s++;AA[pair<int, int> (j,m)]=1;}                  
        }  
      }
    }
    printf("Case #%d: %d\n",i,s);
  }
}
