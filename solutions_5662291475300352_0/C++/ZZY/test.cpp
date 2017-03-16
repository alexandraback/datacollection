#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm> 
#include<cmath>
#include<cstring>
#include<stack> 
#define ll long long
#define oo 105
using namespace std; 
struct node
{
      int D,M; 
}A[11];
int getans(int n)
{
      if (n==1) return 0; 
      if (A[0].D>A[1].D) swap(A[0],A[1]);
      ll L0=360-A[0].D,L1=360-A[1].D;
      ll m,l;
      if (A[0].M<A[1].M)
      {
             m=A[1].M-A[0].M,l=A[0].D+360-A[1].D;
             if (m*L0 >= l*A[0].M) return 1;
             return 0;             
      }
      m=A[0].M-A[1].M,l=360+(A[1].D-A[0].D); //
      if (m*L1 >= l*A[1].M) return 1;
      return 0;      
}
int main()
{
      int Cases,cases;
      freopen("C-small-1-attempt1.in","r",stdin);
      freopen("output.txt","w",stdout);
      scanf("%d",&Cases);
      for (cases=1;cases<=Cases;cases++)
      { 
             int n,t=0;
             scanf("%d",&n);
             while (n--)
             {
                   int D,num,m;
                   scanf("%d%d%d",&D,&num,&m);
                   while (num--)
                       A[t].D=D,A[t++].M=m++;
             }  
             printf("Case #%d: %d\n",cases,getans(t));
      }
      return 0;
}
