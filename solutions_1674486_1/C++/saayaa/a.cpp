#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;
int c[1005][1005]={0},b[1005][1005];
int main()
{
    int t,m=0;
    int n,i,j,a,k;
    cin>>t;
    while(t--)
    {
    int flag=0;
    
    m++;
    cin>>n;
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)
                    {
                                    c[i][j]=0;
                                    }}
    for(i=1;i<=n;i++)
    {
    cin>>a;
    for(j=1;j<=a;j++)
    {
    cin>>b[i][j];
    c[i][b[i][j]]=1;
                    }}
    for(k=1;k<=n;k++)
    {
                     for(i=1;i<=n;i++)
                     {
                                      for(j=1;j<=n;j++)
                                      {
                                                       c[i][j]=(c[i][j]+(c[i][k]*c[k][j]));
                                                       if(c[i][j]>1)
                                                       {
                                                       flag=1;
                                                       break;
                                                       }
                                                       }
                                                       if(flag==1)
                                                       break;
                                                       }
                                                       if(flag==1)
                                                       break;
                                                       }

    
    cout<<"Case #"<<m<<": ";
    if(flag==1)
    cout<<"Yes\n";
    else 
    cout<<"No\n";
    }
    getch();
    return 0;
}
