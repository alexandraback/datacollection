#include<iostream>
#include<cstdio>
#include<string>
#include<cctype>
#include<fstream>
using namespace std;

int a[1005][1005];
int main()
{
    int t,ch=0;
    freopen("A-small-attempt1.in","r",stdin);
     freopen("A-small-attempt1.out","w",stdout);
    cin>>t;
    cin.ignore();
    while(t--)
    {
              ch++;
              int n;
              cin>>n;
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
                                                                 cin>>m;
                                                                 for(j=1;j<=m;j++)
                                                                 {
                                                                                  cin>>num;
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
