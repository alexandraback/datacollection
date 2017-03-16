#include<stdio.h>
#include<iostream>
#include<cstdio>
using namespace std;
int solve(int a[][102],int i,int j, int n, int m)
{
    int l,y=0;
    for(l=0;l<n;l++)
    {
        if(a[l][j]>a[i][j])
        {
            y=1;
            break;
        }
    }
    if(y==1)
   {
       for(l=0;l<m;l++)
        {
            if(a[i][l]>a[i][j])
            return 1;
        }
   }
    return 0;
}
int main()
{
    int t , k=1;
    cin>>t;
    while(k<=t)
    {
        int n,m,i,j,a[102][102],boo=0;
       cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            cin>>a[i][j];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(solve(a,i,j,n,m)==1)
                {
                    boo=1;
                    break;
                }
            }
            if(boo==1)
            break;
        }
        if(boo!=1)
        cout<<"Case #"<<k<<": "<<"YES"<<endl;
        //printf("Case #%d: YES\n",k);
        else
         cout<<"Case #"<<k<<": "<<"NO"<<endl;
       // printf("Case #%d: NO\n",k);
        k++;
    }
    return 0;
}
