#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int main()
{
	 freopen("B-small-attempt0.in","r",stdin);
	 freopen("B-small-attempt0.out","w",stdout);
     int t;
     int k=0;
     scanf("%d",&t);
     while(t>0)
     {
     	  k++;
          t--;
          int n;
          scanf("%d",&n);
          int i,j;
          int sum=0;
          for(i=1;i<=n;i++)
          {
               scanf("%d",&a[i]);
               sum=max(a[i],sum);
          }
          int ans=2100000000,sx;
          for(i=1;i<=sum;i++)
          {
               sx=i;
               for(j=1;j<=n;j++)
                    sx+=(a[j]-1)/i;
               ans=min(sx,ans);
          }
          printf("Case #%d: %d\n",k,ans);
     }
     return 0;
}
