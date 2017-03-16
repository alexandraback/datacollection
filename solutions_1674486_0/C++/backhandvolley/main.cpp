#include <iostream>
#include<stdio.h>
#include<string.h>
#define big long long unsigned int
using namespace std;
big pa[101][101],pa1[101][101];
big temp[100][100]={0};
big temp2[100][100]={0};
void mul(big n,big pa[101][101],big pa1[101][101])
{
big i,j,k,l;

memset(temp2,0,sizeof(temp2));
for(i=1;i<=n;i++)
{
    for(j=1;j<=n;j++)
    {
        temp2[i][j]=pa1[i][j];
    }
}
    for(l=0;l<n-1;l++){

        memset(temp,0,sizeof(temp));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                temp[i][j]+=pa[i][k]*pa1[k][j];
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            pa[i][j]=temp[i][j];
            temp2[i][j]+=temp[i][j];
        }
    }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
   big t,i,n,j,no,p[101],k;
   cin>>t;
   for(i=1;i<=t;i++)
   {
       cin>>n;
       memset(pa,0,sizeof(pa));
       memset(pa1,0,sizeof(pa1));
       for(j=1;j<=n;j++)
       {
           cin>>no;
           pa[j][j]=0;

           for(k=0;k<no;k++)
           {
               cin>>p[k];
               pa[j][p[k]]=1;
               pa[p[k]][j]=0;
           }
       }
       big q,r;
       for(q=1;q<=n;q++)
       {
           for(r=1;r<=n;r++)
           {

               pa1[q][r]=pa[q][r];
           }
       }
       big it;
   mul(n,pa,pa1);
     int flag=0;
     for(k=1;k<=n;k++)
     {
         for(j=1;j<=n;j++)
         {
        //cout<<pa[k][j]<<" ";
             if(temp2[k][j]>=2&&j!=k)
             {
                 flag++;
                 break;
             }
         }
      //  cout<<endl;
     }
     cout<<"Case #"<<i<<": ";
     if(flag)
     {
         cout<<"Yes"<<endl;
     }
     else
     {
         cout<<"No"<<endl;
     }
   }
    return 0;
}
