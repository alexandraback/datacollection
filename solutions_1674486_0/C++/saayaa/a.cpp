#include<iostream>
#include<conio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,m=0;
    int n,i,j,a,b[200][200],k;
    cin>>t;
    while(t--)
    {
    int c[200][200]={0},flag=0;
    m++;
    cin>>n;
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
                                                       flag=1;
                                                       }}}

    
    cout<<"Case #"<<m<<": ";
    if(flag==1)
    cout<<"Yes\n";
    else 
    cout<<"No\n";
    }
    getch();
    return 0;
}
