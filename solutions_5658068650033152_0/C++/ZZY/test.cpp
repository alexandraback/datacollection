#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std; 
int doit(int n,int m,int k)
{
       int ans=n*m,i,j,x;
       for (x=0;x<=k;x++)
         for (i=0;i<n-1;i++)
           for (j=0;j<m-1;j++)
             if ((i+j)*2+i*j>=x)
             {
                 ans=min(ans,k-x+(i+j)*2);  
             }
       return ans;
}
int main()
{ 
       int T,cases,n,m,k;
       freopen("C-small-attempt1.in","r",stdin);
       freopen("output.txt","w",stdout);
       scanf("%d",&T);
       for (cases=1;cases<=T;cases++)
       {  
              scanf("%d%d%d",&n,&m,&k);
              printf("Case #%d: %d\n",cases,doit(n,m,k));
       }
       return 0;
}
