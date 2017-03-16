#include<iostream>
#include<cstdio>

using namespace std;

int a[1005][1005];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
	freopen("out1.txt","w",stdout);
    int t,ch=0;
    scanf("%d",&t);
    while(t--)
    {
              ch++;
              int n;
              scanf("%d",&n);
              int i,j,l;
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
                                                                                  for(l=1;l<=n;l++)
                                                                                  {
                                                                                                   for(i=1;i<=n;i++)
                                                                                                   {
                                                                                                                    for(j=1;j<=n;j++)
                                                                                                                    {
                                                                                                                    if(a[i][l]>0&&a[l][j]>0)
                                                                                                                    {
                                                                                                                    a[i][j]++;
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    l=0;
                                                for(i=1;i<=n;i++)
                                                {
                                                for(j=1;j<=n;j++)
                                                {
                                                if(a[i][j]>=2)
                                                {
                                                l=1;
                                                printf("Case #%d: Yes\n",ch);
                                                break;
                                                }
                                                }
                                                if(l==1)
                                                break;
                                                }
                                                if(!l)
                                                printf("Case #%d: No\n",ch);
                                                }
                                                return 0;
                                                }
