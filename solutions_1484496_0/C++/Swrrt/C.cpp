#include <cstdio>
#include <cstring>
using namespace std;
int hash[2000005]={0},n;
int a[25]={0},zt=0,s=0,fl=0;
void dfs(int p)
{if(p>n)
 {if(hash[s]&&!fl)
  {fl=1;
   int j=0;
   for(int i=1;i<=n;i++)
    if(hash[s]&(1<<(i-1)))
    {if(j)printf(" ");
     j=1;
     printf("%d",a[i]);
    }
   printf("\n");
   j=0;
   for(int i=1;i<=n;i++)
    if(zt&(1<<(i-1)))
    {if(j)printf(" ");
     j=1;
     printf("%d",a[i]);
    }
   printf("\n");
  }
  hash[s]=zt;
  return ;
 }
 dfs(p+1);
 s+=a[p];
 zt|=1<<(p-1);
 dfs(p+1);
 s-=a[p];
 zt^=1<<(p-1);
}    
int main()
{int m,i,j,k,l,T,tt=0;
 freopen("C.in","r",stdin);
 freopen("C.out","w",stdout);
 scanf("%d",&T);
 while(T--)
 {tt++;
  printf("Case #%d:\n",tt);
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  memset(hash,0,sizeof(hash));
  s=0;fl=0;
  dfs(1);
  if(!fl)printf("Impossible\n");
 } 
 return 0;
}
