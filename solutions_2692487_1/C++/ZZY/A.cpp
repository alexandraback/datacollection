#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long 
#define oo 1000000000
#define pi acos(-1.0)
using namespace std;  
int A,N,s[1000005];  
int main()
{
     // freopen("A-large.in","r",stdin); freopen("output.txt","w",stdout); 
      int T,t,i,m,x,k,ans;
      scanf("%d",&T);
      for (t=1;t<=T;t++)
      { 
             scanf("%d%d",&A,&N);
             for (i=1;i<=N;i++) scanf("%d",&s[i]);
             sort(s+1,s+1+N);
             ans=oo; 
             m=0;
             for (i=1;i<=N;i++)
             {
                   x=0;
                   k=A;
                   if (m+N-i+1<ans) ans=m+N-i+1;
                   while (k<=s[i] && x<(N-i+1)) x++,k+=k-1;
                   if (x<(N-i+1)) m+=x,A=k+s[i];
                     else 
                     {
                             m+=N-i+1;
                             break;
                     }
             }
             if (m<ans) ans=m;
             printf("Case #%d: %d\n",t,ans);
      }
      return 0;
}
