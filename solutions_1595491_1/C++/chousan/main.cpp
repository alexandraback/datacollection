#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    freopen("in2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
         for(int cas=1;cas<=t;++cas)
         {
             int n,s,p;
             int a[102];
             scanf("%d%d%d",&n,&s,&p);
             int i;
             int ans=0;
             for(i=0;i<n;++i)
             {
                 scanf("%d",&a[i]);
                 int b=a[i]-p;
                 if(b<0)continue;
                 int c=b/2;
                 if(c>=p-1)ans++;
                 if(c==p-2&&s>0){ans++;s--;}

             }
            printf("Case #%d: %d\n",cas,ans);
         }
}
