#include<iostream>
using namespace std;
int main()
{
    freopen("i1.txt","r",stdin);
    freopen("o1.txt","w",stdout);
    int t,k,n,i,j,l,m,num;
    while(cin>>t)
    {
                 k=0;
                 while(t--)
                 {
                           ++k;
                           cin>>n;
                           int a[n+1][n+1];
                           for(i=0;i<n+1;++i)
                           {
                                             for(j=0;j<n+1;++j)
                                             a[i][j]=0;
                           }
                           for(i=1;i<n+1;++i)
                           {
                                             cin>>m;
                                             for(j=1;j<m+1;++j)
                                             {
                                                               cin>>num;
                                                               ++a[i][num];
                                             }
                           }
                           for(l=1;l<n+1;++l)
                           {
                                             for(i=1;i<=n;i++)
                                             {
                                                              for(j=1;j<=n;j++)
                                                              {
                                                              if(a[i][l]>0&&a[l][j]>0)
                                                              a[i][j]++;
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
                           printf("Case #%d: Yes\n",k);
                           break;
                           }
                           }
                           if(l==1)
                           break;
                           }
                           if(!l)
                           printf("Case #%d: No\n",k);
                 }
                           return 0;
    } 
}
