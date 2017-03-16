#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
   freopen("B-small-attempt0.in","r",stdin);
   freopen("output.out","w",stdout);
   int t,a,b;
   scanf("%d",&t);
   for(int k=0;k<t;k++)
   {
       int n,m,a[101][101],row[101],col[101];
    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
    {
        int temp=0;
        row[i]=0;
        for(int j=1;j<=m;j++)
        {
        scanf("%d",&a[i][j]);
        temp=(a[i][j]>temp)?a[i][j]:temp;
        }
        row[i]=temp;

    }
     for(int j=1;j<=m;j++)
        {
        int temp=0;
        col[j]=0;
        for(int i=1;i<=n;i++)
           temp=(a[i][j]>temp)?a[i][j]:temp;
        col[j]=temp;
        }
        int flag=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(a[i][j]!=row[i]&&a[i][j]!=col[j]) flag=0;
            printf("Case #%d: ",k+1);
        if(flag)
            printf("YES\n");
        else printf("NO\n");

   }
   return 0;
}
