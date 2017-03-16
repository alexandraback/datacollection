#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int a[10001];
int main()
{
	 freopen("A-small-attempt0.in","r",stdin);
	 freopen("A-small-attempt0.out","w",stdout);
     int t;
     int k=0;
     scanf("%d",&t);
     while(t>0)
     {
     	  k++;
          t--;
          int n;
          scanf("%d",&n);
          string x;
          cin>>x;
          int i;
          for(i=0;i<=n;i++)
               a[i]=x[i]-'0';
          int ans=0,sum=a[0];
          for(i=1;i<=n;i++)
          {
               if(sum<i)
               {
                    ans+=i-sum;
                    sum+=i-sum;
               }
               sum+=a[i];
          }
          printf("Case #%d: %d\n",k,ans);
     }
     return 0;
}
