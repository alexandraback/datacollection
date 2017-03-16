#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int t;
int n,J;
int m;
int main()
{
    int i,j,k,times;
    
    freopen("data.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    n=32;J=500;
    
    cout<<"Case #1:"<<endl;
    
    for(i=0;i<J;i++)
    {
       m=(n-4)/2;
       
       
       cout<<11;
       
       for(j=1;j<=m;j++)
       {
           if((i&(1<<(j-1)))!=0)
           {
               cout<<11;
           }
           else
           {
               cout<<0<<0;
           }
       }
       cout<<11;
       for(j=2;j<=10;j++)
       {
           cout<<' '<<j+1;
       }
       cout<<endl;
       
    }
    
    
    return 0;
}
