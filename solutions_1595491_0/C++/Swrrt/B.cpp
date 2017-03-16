#include <cstdio>
#include <cstring>
using namespace std;
int a[105]={0};
int main()
{int n,m,i,j,k,l,T,tt,p,ans=0;
 freopen("B.in","r",stdin);
 freopen("B.out","w",stdout);
 scanf("%d",&T);
 tt=0;
 while(T--)
 {tt++;
  scanf("%d%d%d",&n,&m,&p);
  ans=0;
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=n;i++)
  {j=0;
   while(j*3<a[i])j++;
   if(a[i]%3==0)
   {if(j>=p)ans++;
    else if(a[i]>0&&m>0&&j+1>=p){ans++;m--;}
   }else if(a[i]%3==2)
   {if(j>=p)ans++;
    else if(m>0&&j+1>=p){ans++,m--;}
   }
   else
   {if(j>=p)ans++;}
  }
  printf("Case #%d: %d\n",tt,ans);
 }
 return 0;
}
