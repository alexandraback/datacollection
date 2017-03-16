#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
     if(b==0)
     return a;
     return gcd(b,a%b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,cases,i;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    long long n1,n2,n;
    double ans;
    char A[30];
    scanf("%d",&t);
    cases=0;
    while(t-cases++)
    {
              scanf("%s",A);
              n1=n2=0;
              for(i=0;A[i]!='/';i++)
              {
                 n1*=10;
                 n1+=A[i]-48;
              }
              i++;
              for(;A[i]!='\0';i++)
              {
                 n2*=10;
                 n2+=A[i]-48;
              }
              if(n1>n2)
              {
                       printf("Case #%d: impossible\n",cases);
                       continue;
              }
              n=gcd(n1,n2);
              n1/=n;
              n2/=n;
              ans=log2(n2);
              if(ans!=(int)ans)
              {
                       printf("Case #%d: impossible\n",cases);
                       continue;
              }
              if(n1==1) 
                    printf("Case #%d: %d\n",cases,(int)ans);
              else
              {
              for(i=0;i<ans;i++)
              {
                  if(n1>=(n2/2))
                  break;
                  n2/=2;
              }
              printf("Case #%d: %d\n",cases,i+1);
              }
    }
    return 0;
}
