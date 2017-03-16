#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

#define MOD 1000000007
#define INF 2000000000

using namespace std;

bool check(int d)
{
     while(d%2==0)
     {
                  d/=2;
     }
     
     if(d==1)
      return true;
     
     return false;
}

long long gcd(long long a,long long b)
{
     if(b==0)
      return a;
     
     return gcd(b,a%b);
}

int main()
{
    int t;
    
    long long n,d;
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    scanf("%d",&t);
    int sv=t;
    
    while(t--)
    {
              scanf("%lld/%lld",&n,&d);
              
              long long x=gcd(n,d);
              n/=x;
              d/=x;
              
              //printf("%lld\n",x);
              
              int cnt=0;
              
              if(!check(d))
              {
                           printf("Case #%d: impossible\n",sv-t);
                           continue;
              }
                          
              
              while(n<d)
              {
                         n*=2ll;
                         cnt++;
              }
              
              printf("Case #%d: %d\n",sv-t,cnt);
    }
              
              
              
    
    return 0;
}
