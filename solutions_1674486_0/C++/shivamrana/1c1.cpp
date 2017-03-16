#include<iostream>
#include<cstdio>
 
using namespace std;
 
int a[1005][1005];
int main()
{
    int t,ch=0;
    scanf("%d",&t);
    while(t--)
    {
              ch++;
              int n;
              scanf("%d",&n);
              int i,j,k;
              for(i=0;i<=n;i++)
              {
                               for(j=0;j<=n;j++)
                               {
                                                a[i][j]=0;
                                                }
                                                }
                                                int m,num;
                                                for(i=1;i<=n;i++)
                                                {
                                                                 scanf("%d",&m);
                                                                 for(j=1;j<=m;j++)
                                                                 {
                                                                                  scanf("%d",&num);
                                                                                  a[i][num]++;
                                                                                  }
                                                                                  }
                                                                                  for(k=1;k<=n;k++)
                                                                                  {
                                                                                                   for(i=1;i<=n;i++)
                                                                                                   {
                                                                                                                    for(j=1;j<=n;j++)
                                                                                                                    {
                                                                                                                    if(a[i][k]>0&&a[k][j]>0)
                                                                                                                    {
                                                                                                                    a[i][j]++;
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    k=0;
                                                for(i=1;i<=n;i++)
                                                {
                                                for(j=1;j<=n;j++)
                                                {
                                                if(a[i][j]>=2)
                                                {
                                                k=1;
                                                printf("Case #%d: Yes\n",ch);
                                                break;
                                                }
                                                }
                                                if(k==1)
                                                break;
                                                }
                                                if(!k)
                                                printf("Case #%d: No\n",ch);
                                                }
                                                return 0;
                                                }