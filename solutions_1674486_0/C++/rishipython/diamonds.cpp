#include<iostream>
#include<cstdio>
 
using namespace std;
 
int G[1005][1005];
int main()
{
    int t,chis=0;
    scanf("%d",&t);
    while(t--)
    {
              chis++;
              int n;
              scanf("%d",&n);
              int i,j,k;
              for(i=0;i<=n;i++)
              {
                               for(j=0;j<=n;j++)
                               {
                                                G[i][j]=0;
                                                }
                                                }
                                                int m,num;
                                                for(i=1;i<=n;i++)
                                                {
                                                                 scanf("%d",&m);
                                                                 for(j=1;j<=m;j++)
                                                                 {
                                                                                  scanf("%d",&num);
                                                                                  G[i][num]++;
                                                                                  }
                                                                                  }
                                                                                  for(k=1;k<=n;k++)
                                                                                  {
                                                                                                   for(i=1;i<=n;i++)
                                                                                                   {
                                                                                                                    for(j=1;j<=n;j++)
                                                                                                                    {
                                                                                                                    if(G[i][k]>0&&G[k][j]>0)
                                                                                                                    {
                                                                                                                    G[i][j]++;
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    }
                                                                                                                    k=0;
                                                for(i=1;i<=n;i++)
                                                {
                                                for(j=1;j<=n;j++)
                                                {
                                                if(G[i][j]>=2)
                                                {
                                                k=1;
                                                printf("Case #%d: Yes\n",chis);
                                                break;
                                                }
                                                }
                                                if(k==1)
                                                break;
                                                }
                                                if(!k)
                                                printf("Case #%d: No\n",chis);
                                                }
                                                return 0;
                                                }
                                                
                                                
                                                                                                                    
                                                                                  
                                                                 
                                                
 
