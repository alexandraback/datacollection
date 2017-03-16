#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int a[10001];
int main()
{
	 freopen("A-large.in","r",stdin);
	 freopen("A-large.out","w",stdout);
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
               if(sum<i&&a[i]!=0)
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
