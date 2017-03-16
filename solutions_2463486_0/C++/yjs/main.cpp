#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<vector>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;
long long  n,m,num;
long long a[100006];
bool judge(long long x)
{
       char str[20];
       int i=0;
       while(x)
       {
              str[i++]=x%10;
              x/=10;
       }
       for(int j=0;j<i/2;j++)
              if(str[j]!=str[i-j-1])
                     return false;
       return true;
}
void cal()
{
       for(int i=1;i<=10000000;i++)
              if(judge(i))
                     a[num++]=i;
}
void solve()
{
       int r,l,ans=0;
   for(l=0;l<num;l++)
       if(a[l]*a[l]>=n)
              break;
   for(r=l;r<num;r++)
       if(a[r]*a[r]>m)
              break;
   r--;
   for(int i=l;i<=r;i++)
       if(judge(a[i]*a[i]))
              ans++;
   printf("%d\n",ans);
}
int main()
{
       freopen("in.in","r",stdin);
       freopen("out.out","w",stdout);
       int ca;
       cal();
       scanf("%d",&ca);
       for(int i=1;i<=ca;i++)
       {
              cin>>n>>m;
              printf("Case #%d: ",i);
              solve();
       }
      return 0;
}
