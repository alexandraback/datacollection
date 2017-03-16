/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
long long reverse(long long x)
{
     long long r=0,d;
     while(x>0)
     {
               d=x%10;
               r=r*10+d;
               x=x/10;
     }
     return r;
}
     
bool palin(long long x)
{
     long long y=reverse(x);
     if(x==y)
     return 1;
     return 0;
}
vector<long long> piggi;
void pre()
{
     for(long long i=1;i<10000001;i++)
     {
             if(palin(i))
             {
                                
                                long long j=i*i;
                                if(palin(j))
                                piggi.push_back(j);
                                
             }
     }
}
     
int main()
{
    freopen("input.in","r",stdin);
    freopen("output1.out","w",stdout);
     int t,k=0,cases=0,c1,c2;
     long long j,a,b;
     pre();
     scanf("%d",&t);
     for(cases=1;cases<=t;cases++)
     {
               printf("Case #%d: ",cases);
               scanf("%lld%lld",&a,&b);
               if(a>piggi[piggi.size()-1])
               {printf("0\n");continue;}
               if(b>piggi[piggi.size()-1])
               b=piggi[piggi.size()-1];
               for(int i=0;i<piggi.size();i++)
               {
                       if(piggi[i]>=a)
                       {c1=i;
                       break;}
               }
               for(int i=0;i<piggi.size();i++)
               {
                       if(piggi[i]<=b)
                       c2=i;
               }
               printf("%d\n",c2-c1+1);        
     
     }
     return 0;
}
